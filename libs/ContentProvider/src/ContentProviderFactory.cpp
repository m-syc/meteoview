#include "ContentProviderFactory.hpp"
#include "ChmiProvider.hpp"
#include "ModellzentraleProvider.hpp"
#include <iostream>
#include <fstream>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<std::shared_ptr<ContentProvider>> ContentProviderFactory::createProviders() {
    std::vector<std::shared_ptr<ContentProvider>> providers;
    std::string cfgPath = "./config.json";

    std::ifstream f{cfgPath};
    json config = json::parse(f);

    for (const auto& [service_name, properties] : config["services"].items()) {
        if(properties["process"]) {
            auto provider = ContentProviderFactory::createProvider(service_name, properties);
            if(provider != nullptr) {
                providers.push_back(provider);
            }
        }
    }

    return providers;
}

std::shared_ptr<ContentProvider> ContentProviderFactory::makeChmiProvier(const json& j_cfg) {
    // Config deserialized from json
    const ChmiCfg cfg = j_cfg.get<ChmiCfg>();

    return std::shared_ptr<ChmiProvider>(new ChmiProvider{cfg});
}

std::shared_ptr<ContentProvider> ContentProviderFactory::makeModellzentraleProvider(const json& j_cfg) {
    // Config deserialized from json
    ModellzentraleCfg cfg = j_cfg.get<ModellzentraleCfg>();

    return std::shared_ptr<ModellzentraleProvider>(new ModellzentraleProvider{cfg});
}

std::shared_ptr<ContentProvider> ContentProviderFactory::createProvider(const std::string &serviceName, const json& j_cfg) {
    // LUT that maps meteorological service names to their respective service implementations
    using ServiceRegistry = std::map<std::string, std::function<std::shared_ptr<ContentProvider>(const nlohmann::json& cfg)>>;

    static const ServiceRegistry serviceMap = {
        {"Chmi", &ContentProviderFactory::makeChmiProvier},
        {"Modellzentrale", &ContentProviderFactory::makeModellzentraleProvider},
    };

    auto creator = serviceMap.find(serviceName);
    if(creator != serviceMap.end()) {
        return creator->second(j_cfg);
    }
    else {
        fmt::print("ERROR: cannot find key {}", serviceName);
        return nullptr;
    }
}