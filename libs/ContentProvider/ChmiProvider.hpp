#ifndef _CHMI_PROVIDER
#define _CHMI_PROVIDER

#include <memory>
#include "ContentProvider.hpp"
// #include "CfgReader.hpp"

class ChmiProvider : public ContentProvider {
public:
    ~ChmiProvider();

    void fetchContent();
    ChmiProvider(ChmiProvider& instance) = delete;
    static std::shared_ptr<ChmiProvider> instance(std::shared_ptr<BasicCfg> cfg);
private:
    ChmiProvider();
    ChmiProvider(std::shared_ptr<ChmiCfg> cfg);
    std::shared_ptr<BasicCfg> cfg;
};

#endif /* _CHMI_PROVIDER */