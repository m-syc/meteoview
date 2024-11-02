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
    for(auto service : config["services"]) {
        if(service["name"] == "Chmi") {
            serviceCfgs.insert({MeteoService::Chmi, std::shared_ptr<BasicCfg>(new ChmiCfg{})});
        }
        else if(service["name"] == "Modellzentrale") {
            serviceCfgs.insert({MeteoService::Modellzentrale, std::shared_ptr<BasicCfg>(new ModellzentraleCfg{})});
        }
    }
}

CfgReader::~CfgReader() {
}

std::shared_ptr<BasicCfg> CfgReader::get(MeteoService type) noexcept {
    return serviceCfgs.at(type);
}
