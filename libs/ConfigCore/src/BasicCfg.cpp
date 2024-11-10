#include "BasicCfg.hpp"
#include "fmt/core.h"
#include <nlohmann/json.hpp>

ChmiCfg::ChmiCfg() {}

// ChmiCfg::ChmiCfg(cost json &j) {

// }
using json = nlohmann::json;

void to_json(json &j, const ChmiCfg &cfg) noexcept {
    j["process"] = cfg.doProcess;
    j["imgNumber"] = cfg.imgNum;
}

void from_json(const json& j, ChmiCfg &cfg) noexcept {
    try {
        j.at("process").get_to(cfg.doProcess);
        j.at("imgNumber").get_to(cfg.imgNum);
    }
    catch(const json::out_of_range &e) {
        fmt::print("Message: {}\n", e.what());
    }
}

void to_json(json &j, const ModellzentraleCfg &cfg) noexcept {
    j["process"] = cfg.doProcess;
    j["imgNumber"] = cfg.imgNum;
}

void from_json(const json& j, ModellzentraleCfg &cfg) noexcept {
    try {
        j.at("process").get_to(cfg.doProcess);
        j.at("imgNumber").get_to(cfg.imgNum);
    }
    catch(const json::out_of_range &e) {
        fmt::print("Message: {}\n", e.what());
    }
}

ModellzentraleCfg::ModellzentraleCfg() {}
