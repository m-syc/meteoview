#ifndef _BASIC_CFG
#define _BASIC_CFG

#include "fmt/core.h"
#include <nlohmann/json.hpp>


class BasicCfg {
public:
    BasicCfg() = default;

    virtual ~BasicCfg() = default;

protected:
    unsigned int imgNum;
    bool doProcess;
};

class ChmiCfg : public BasicCfg {
public:
    enum Products {
        IR,
        IR_BT,
        Airmass,
    };

    ChmiCfg();
    ~ChmiCfg() = default;

    friend void to_json(nlohmann::json &k, const ChmiCfg &cfg) noexcept;
    friend void from_json(const nlohmann::json& j, ChmiCfg &cfg) noexcept;

private:
    std::vector<Products> products;
};

class ModellzentraleCfg : public BasicCfg {
public:
    enum Altitude {
        ALT_900 = 900,
        ALT_750 = 750,
        ALT_500 = 500
    };

    ModellzentraleCfg();
    // ModellzentraleCfg(json j);
    ~ModellzentraleCfg() = default;

    friend void to_json(nlohmann::json &k, const ModellzentraleCfg &cfg) noexcept;
    friend void from_json(const nlohmann::json& j, ModellzentraleCfg &cfg) noexcept;
private:
};

#endif /* _BASIC_CFG */