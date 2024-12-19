#ifndef _BASIC_CFG
#define _BASIC_CFG

#include "fmt/core.h"
#include <nlohmann/json.hpp>


class BasicCfg {
public:
    BasicCfg() = default;

    virtual ~BasicCfg() = default;

// protected:
    unsigned int imgNum;
    bool doProcess;
};

#endif /* _BASIC_CFG */