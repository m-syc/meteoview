#ifndef _CONTENT_PROVIDER_FACTORY
#define _CONTENT_PROVIDER_FACTORY

#include <map>
#include <memory>
#include <functional>
#include <nlohmann/json.hpp>
#include "ContentProvider.hpp"

class ContentProviderFactory {
public:
    static std::vector<std::shared_ptr<ContentProvider>> createProviders();

private:

    static std::shared_ptr<ContentProvider> makeChmiProvier(const nlohmann::json& j_cfg);
    static std::shared_ptr<ContentProvider> makeModellzentraleProvider(const nlohmann::json& j_cfg);
    static std::shared_ptr<ContentProvider> createProvider(const std::string &serviceName, const nlohmann::json& j_cfg);
};



#endif /* _CONTENT_PROVIDER_FACTORY */
