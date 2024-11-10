#include "CfgReader.hpp"
#include <fstream>
#include <iostream>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using std::ios;

CfgReader::CfgReader(std::filesystem::path cfgPath) noexcept :
        cfgPath{cfgPath} {

    std::ifstream f(cfgPath);
    json config = json::parse(f);
    for (const auto& [service_name, properties] : config["services"].items()) {
        if(properties["process"]) {
            std::cout << service_name << std::endl;
            std::cout << properties << std::endl;
        }
    }
    // for(auto service : config["services"]) {
    //     if(service["name"] == "Chmi") {
    //         serviceCfgs.insert({MeteoService::Chmi, std::shared_ptr<BasicCfg>(new ChmiCfg{service["properties"]})});
    //     }
    //     else if(service["name"] == "Modellzentrale") {
    //         serviceCfgs.insert({MeteoService::Modellzentrale, std::shared_ptr<BasicCfg>(new ModellzentraleCfg{service["properties"]})});
    //     }
    // }
    // // initialize other services
    // for(auto service : MeteoService()) {
    //     if(serviceCfgs.find(service) == serviceCfgs.end()) {
    //         serviceCfgs.insert({service, std::shared_ptr<BasicCfg>(new BasicCfg{})});
    //     }
    // }
}

CfgReader::~CfgReader() {
}
