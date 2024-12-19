#include "ModellzentraleCfg.hpp"

NLOHMANN_JSON_SERIALIZE_ENUM(ModellzentraleCfg::Altitude, {
    {ModellzentraleCfg::ALT_INVALID, 0},
    {ModellzentraleCfg::ALT_900, 900},
    {ModellzentraleCfg::ALT_750, 750},
    {ModellzentraleCfg::ALT_500, 500},
})

using json = nlohmann::json;

void to_json(json &j, const ModellzentraleCfg &cfg) noexcept {
    j["process"] = cfg.doProcess;
    j["imgNumber"] = cfg.imgNum;
    j["altitude"] = cfg.altitudes;
}

void from_json(const json& j, ModellzentraleCfg &cfg) noexcept {
    try {
        j.at("process").get_to(cfg.doProcess);
        j.at("imgNumber").get_to(cfg.imgNum);
        j.at("altitude").get_to(cfg.altitudes);
    }
    catch(const json::out_of_range &e) {
        fmt::print("Message: {}\n", e.what());
    }
}
