#ifndef _SAT24_CFG
#define _SAT24_CFG

#include "BasicCfg.hpp"

class Sat24Cfg : public BasicCfg {
public:
    enum Product {
        PROD_INVALID,
        PROD_VISIBLE,
        PROD_INFRARED,
        PROD_NIGHTMICROPHYSICS,
        PROD_RADAR_AND_SATELITE,
    };

    Sat24Cfg() = default;
    ~Sat24Cfg() = default;

    friend void to_json(nlohmann::json &k, const Sat24Cfg &cfg) noexcept;
    friend void from_json(const nlohmann::json& j, Sat24Cfg &cfg) noexcept;

private:
    std::vector<Product> products;
};

#endif /* _SAT24_CFG */