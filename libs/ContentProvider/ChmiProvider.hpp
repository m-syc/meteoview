#ifndef _CHMI_PROVIDER
#define _CHMI_PROVIDER

#include <memory>
#include "ContentProvider.hpp"
#include <nlohmann/json.hpp>
// #include "CfgReader.hpp"

class ChmiProvider : public ContentProvider {
public:
    ~ChmiProvider();

    void fetchContent();
    ChmiProvider();
    ChmiProvider(const ChmiCfg &cfg);
    ChmiProvider(ChmiProvider& instance) = delete;
private:
};

#endif /* _CHMI_PROVIDER */