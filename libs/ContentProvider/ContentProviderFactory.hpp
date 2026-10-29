#pragma once

#include <nlohmann/json.hpp>
#include "ContentProvider.hpp"

namespace Provider {

class ContentProviderFactory {
public:
    static std::vector<std::unique_ptr<ContentProvider>> createProviders();

private:

    static std::unique_ptr<ContentProvider> makeSat24Provier(const nlohmann::json& j_cfg);
    static std::unique_ptr<ContentProvider> makeChmiProvier(const nlohmann::json& j_cfg);
    static std::unique_ptr<ContentProvider> makeModellzentraleProvider(const nlohmann::json& j_cfg);
    static std::unique_ptr<ContentProvider> createProvider(const std::string &serviceName, const nlohmann::json& j_cfg);
};

}
