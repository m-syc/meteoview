#ifndef _MODELLZENTRALE_PROVIDER
#define _MODELLZENTRALE_PROVIDER

#include <memory>
#include "ContentProvider.hpp"
#include "CfgReader.hpp"

class ModellzentraleProvider : public ContentProvider {
public:
    ~ModellzentraleProvider();

    void fetchContent() noexcept;
    ModellzentraleProvider();
    ModellzentraleProvider(const ModellzentraleCfg &cfg);
    ModellzentraleProvider(ModellzentraleProvider& instance) = delete;
private:
};

#endif /* _MODELLZENTRALE_PROVIDER */
