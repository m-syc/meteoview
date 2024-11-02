#include "ChmiProvider.hpp"
#include <fmt/core.h>
#include <restbed>

ChmiProvider::ChmiProvider() {
    fmt::print("{} constructor\n", __FUNCTION__);
}

ChmiProvider::ChmiProvider(std::shared_ptr<ChmiCfg> cfg) {
    fmt::print("{} constructor with cfg\n", __FUNCTION__);
}

ChmiProvider::~ChmiProvider() {
    fmt::print("{} destructor\n", __FUNCTION__);
}

std::shared_ptr<ChmiProvider> ChmiProvider::instance(std::shared_ptr<BasicCfg> cfg) {
    auto chmiProvider = new ChmiProvider{std::static_pointer_cast<ChmiCfg>(cfg)};
    static auto contentProvider = std::shared_ptr<ChmiProvider>(chmiProvider);

    return contentProvider;
}

void ChmiProvider::fetchContent() {
    // auto request = std::make_shared<restbed::Request>(restbed::Uri("http://www.example.com"));
    // request->set_header("Accept", "*/*");
    // request->set_header("Host", "www.example.com");

    // auto response = restbed::Http::sync(request);
    // fmt::print("response code: {}\n", response->get_status_code());
}
