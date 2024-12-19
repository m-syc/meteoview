#ifndef _CHMI_CFG
#define _CHMI_CFG

#include "BasicCfg.hpp"

class ChmiCfg : public BasicCfg {
public:
    enum Product {
        PROD_INVALID,
        PROD_IR,
        PROD_IR_BT,
        PROD_VIS_IR,
        PROD_WV,
        PROD_Airmass,
        PROD_24H_M,
        PROD_NIGHT_M,
    };

    enum Area {
        AREA_INVALID,
        AREA_EU,
        AREA_CE,
        AREA_CZ,
    };

    enum Timedelta {
        TD_15MIN = 15,
        TD_30MIN = 30,
        TD_60MIN = 60,
    };

    ChmiCfg() = default;
    ~ChmiCfg() = default;

    friend void to_json(nlohmann::json &k, const ChmiCfg &cfg) noexcept;
    friend void from_json(const nlohmann::json& j, ChmiCfg &cfg) noexcept;

// private:
    std::vector<Product> products;
    std::string area;
    Timedelta td;

private:
    void removeInvalidates(std::vector<ChmiCfg::Product> &products);
};

#endif /* _CHMI_CFG */