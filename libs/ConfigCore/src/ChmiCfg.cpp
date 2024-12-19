#include "ChmiCfg.hpp"
#include <fmt/core.h>

NLOHMANN_JSON_SERIALIZE_ENUM(ChmiCfg::Product, {
    {ChmiCfg::PROD_INVALID, ""},
    {ChmiCfg::PROD_IR, "IR"},
    {ChmiCfg::PROD_IR_BT, "IR BT"},
    {ChmiCfg::PROD_VIS_IR, "VIS-IR"},
    {ChmiCfg::PROD_WV, "WV"},
    {ChmiCfg::PROD_Airmass, "Airmass"},
    {ChmiCfg::PROD_24H_M, "24h-M"},
    {ChmiCfg::PROD_NIGHT_M, "night-M"},
})

using json = nlohmann::json;

void to_json(json &j, const ChmiCfg &cfg) noexcept {
    j["process"] = cfg.doProcess;
    j["imgNumber"] = cfg.imgNum;
    j["products"] = cfg.products;
    j["area"] = cfg.area;
    j["timedelta"] = cfg.td;
}

void from_json(const json& j, ChmiCfg &cfg) noexcept {
    try {
        j.at("process").get_to(cfg.doProcess);
        j.at("imgNumber").get_to(cfg.imgNum);
        j.at("products").get_to(cfg.products);
        j.at("area").get_to(cfg.area);
        j.at("timedelta").get_to(cfg.td);

        cfg.removeInvalidates(cfg.products);
    }
    catch(const json::out_of_range &e) {
        fmt::print("Message: {}\n", e.what());
    }
}

void ChmiCfg::removeInvalidates(std::vector<ChmiCfg::Product> &products) {
    for(auto it = products.begin(); it != products.end(); ) {
        if(*it == ChmiCfg::PROD_INVALID) {
            products.erase(it);
        }
        else {
            ++it;
        }
    }
}
