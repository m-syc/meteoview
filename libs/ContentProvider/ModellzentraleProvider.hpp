#ifndef _MODELLZENTRALE_PROVIDER
#define _MODELLZENTRALE_PROVIDER

#include <memory>
#include "ContentProvider.hpp"
#include "CfgReader.hpp"

class ModellzentraleProvider : public ContentProvider {
public:
    ~ModellzentraleProvider();

    void fetchContent() noexcept;
    ModellzentraleProvider(ModellzentraleProvider& instance) = delete;
    static std::shared_ptr<ModellzentraleProvider> instance(std::shared_ptr<BasicCfg> cfg);
private:
    ModellzentraleProvider();
    ModellzentraleProvider(std::shared_ptr<ModellzentraleCfg> cfg);
};

#endif /* _MODELLZENTRALE_PROVIDER */
