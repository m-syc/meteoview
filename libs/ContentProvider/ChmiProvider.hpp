#pragma once

#include <memory>
#include "ContentProvider.hpp"
#include <nlohmann/json.hpp>
#include "ChmiCfg.hpp"

namespace Provider {

class ChmiProvider : public ContentProvider {
public:
    ~ChmiProvider();

    void fetchContent();
    ChmiProvider();
    ChmiProvider(const ChmiCfg &cfg);
    ChmiProvider(ChmiProvider& instance) = delete;

    void reloadConfig(const ChmiCfg &cfg);
    // std::vector<Product>& 

private:

    ChmiCfg cfg;
};

}
