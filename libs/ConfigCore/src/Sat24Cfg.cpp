#include "Sat24Cfg.hpp"

NLOHMANN_JSON_SERIALIZE_ENUM(Sat24Cfg::Product, {
    {Sat24Cfg::PROD_INVALID ,""},
    {Sat24Cfg::PROD_VISIBLE ,"Visible"},
    {Sat24Cfg::PROD_INFRARED ,"Infrared"},
    {Sat24Cfg::PROD_NIGHTMICROPHYSICS ,"nightmicrophysics"},
    {Sat24Cfg::PROD_RADAR_AND_SATELITE ,"Radar and satelite"},
})

using json = nlohmann::json;

void to_json(json &j, const Sat24Cfg &cfg) noexcept {
    j["process"] = cfg.doProcess;
    j["imgNumber"] = cfg.imgNum;
    j["products"] = cfg.products;
}

void from_json(const json& j, Sat24Cfg &cfg) noexcept {
    try {
        j.at("process").get_to(cfg.doProcess);
        j.at("imgNumber").get_to(cfg.imgNum);
        j.at("products").get_to(cfg.products);
    }
    catch(const json::out_of_range &e) {
        fmt::print("Message: {}\n", e.what());
    }
}