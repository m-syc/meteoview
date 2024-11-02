#include "ModellzentraleProvider.hpp"
#include <fmt/core.h>
#include <restbed>

ModellzentraleProvider::ModellzentraleProvider() {
    // fmt::print("{} constructor\n", __FUNCTION__);
}

ModellzentraleProvider::ModellzentraleProvider(std::shared_ptr<ModellzentraleCfg> cfg) {
    fmt::print("{} constructor with cfg\n", __FUNCTION__);
}

ModellzentraleProvider::~ModellzentraleProvider() {
    // fmt::print("{} destructor\n", __FUNCTION__);
}

std::shared_ptr<ModellzentraleProvider> ModellzentraleProvider::instance(std::shared_ptr<BasicCfg> cfg) {
    auto modellzentraleProvider = new ModellzentraleProvider{std::static_pointer_cast<ModellzentraleCfg>(cfg)};
    static auto contentProvider = std::shared_ptr<ModellzentraleProvider>(modellzentraleProvider);

    return contentProvider;
}

void ModellzentraleProvider::fetchContent() noexcept {
    // auto request = std::make_shared<restbed::Request>(restbed::Uri("http://www.example.com"));
    // request->set_header("Accept", "*/*");
    // request->set_header("Host", "www.example.com");

    // auto response = restbed::Http::sync(request);
    // fmt::print("response code: {}\n", response->get_status_code());
}
