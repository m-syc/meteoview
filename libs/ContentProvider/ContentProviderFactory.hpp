#ifndef _CONTENT_PROVIDER_FACTORY
#define _CONTENT_PROVIDER_FACTORY

#include <map>
#include <memory>
#include "ChmiProvider.hpp"
#include "ModellzentraleProvider.hpp"

class ContentProviderFactory {
public:
    static std::map<MeteoService, std::shared_ptr<ContentProvider>> createProviders() {
        CfgReader cfg{"./config.json"};
        auto chmi = ChmiProvider::instance(cfg.get(MeteoService::Chmi));
        auto mdlzntrl = ModellzentraleProvider::instance(cfg.get(MeteoService::Modellzentrale));

        return {{MeteoService::Modellzentrale, mdlzntrl},
                {MeteoService::Chmi, chmi}};
    }
};

#endif /* _CONTENT_PROVIDER_FACTORY */
