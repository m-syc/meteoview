#ifndef _BASIC_CFG
#define _BASIC_CFG

#include "fmt/core.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class BasicCfg {
public:
    BasicCfg() = default;

    virtual ~BasicCfg() = default;

private:
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
    ChmiCfg(json j);
    ~ChmiCfg() = default;

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
    ModellzentraleCfg(json j);
    ~ModellzentraleCfg() = default;
private:
};

#endif /* _BASIC_CFG */