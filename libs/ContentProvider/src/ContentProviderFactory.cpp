#include "ContentProviderFactory.hpp"
#include "Sat24Provider.hpp"
#include "ChmiProvider.hpp"
#include "ModellzentraleProvider.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include <memory>
#include <functional>
#include <stdexcept>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace Provider {

std::vector<std::unique_ptr<ContentProvider>> ContentProviderFactory::createProviders() {
    std::vector<std::unique_ptr<ContentProvider>> providers;
    const std::string cfgPath = (std::filesystem::path(PROJECT_ROOT_DIR) / "config.json").string();

    std::ifstream f{cfgPath};
    if(!f.is_open()) {
        throw std::runtime_error("Cannot open config file: " + cfgPath);
    }
    json config = json::parse(f);

    for(const auto& [service_name, properties] : config["services"].items()) {
        if(properties["process"]) {
            auto provider = ContentProviderFactory::createProvider(service_name, properties);
            if(provider != nullptr) {
                providers.emplace_back(std::move(provider));
            }
        }
    }

    return providers;
}

std::unique_ptr<ContentProvider> ContentProviderFactory::makeSat24Provier(const json& j_cfg) {
    const Sat24Cfg cfg = j_cfg.get<Sat24Cfg>();

    return std::make_unique<Sat24Provider>(cfg);
}

std::unique_ptr<ContentProvider> ContentProviderFactory::makeChmiProvier(const json& j_cfg) {
    const ChmiCfg cfg = j_cfg.get<ChmiCfg>();

    return std::make_unique<ChmiProvider>(cfg);
}

std::unique_ptr<ContentProvider> ContentProviderFactory::makeModellzentraleProvider(const json& j_cfg) {
    ModellzentraleCfg cfg = j_cfg.get<ModellzentraleCfg>();

    return std::make_unique<ModellzentraleProvider>(cfg);
}

std::unique_ptr<ContentProvider> ContentProviderFactory::createProvider(const std::string &serviceName, const json& j_cfg) {
    // LUT that maps meteorological service names to their respective service implementations
    using ServiceRegistry = std::map<std::string, std::function<std::unique_ptr<ContentProvider>(const nlohmann::json& cfg)>>;

    static const ServiceRegistry serviceMap = {
        {"sat24", &ContentProviderFactory::makeSat24Provier},
        {"Chmi", &ContentProviderFactory::makeChmiProvier},
        {"Modellzentrale", &ContentProviderFactory::makeModellzentraleProvider},
    };

    const auto& creator = serviceMap.find(serviceName);
    if(creator != serviceMap.end()) {
        return creator->second(j_cfg);
    }
    else {
        fmt::print("ERROR: cannot find key {}", serviceName);
        return nullptr;
    }
}

}
