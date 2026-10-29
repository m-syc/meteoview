#pragma once

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
