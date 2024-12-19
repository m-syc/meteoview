#ifndef _MODELLZENTRALE_CFG
#define _MODELLZENTRALE_CFG

#include "BasicCfg.hpp"

class ModellzentraleCfg : public BasicCfg {
public:
    enum Altitude {
        ALT_INVALID,
        ALT_900 = 900,
        ALT_750 = 750,
        ALT_500 = 500
    };

    ModellzentraleCfg() = default;
    // ModellzentraleCfg(json j);
    ~ModellzentraleCfg() = default;

    friend void to_json(nlohmann::json &k, const ModellzentraleCfg &cfg) noexcept;
    friend void from_json(const nlohmann::json& j, ModellzentraleCfg &cfg) noexcept;
private:
    std::vector<Altitude> altitudes;
};

#endif /* _MODELLZENTRALE_CFG */