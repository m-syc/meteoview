#include "ChmiProvider.hpp"
#include <fmt/core.h>
#include <restbed>

ChmiProvider::ChmiProvider() {
    fmt::print("{} constructor\n", __FUNCTION__);
}

ChmiProvider::ChmiProvider(const ChmiCfg &cfg) {
    fmt::print("{} constructor with cfg\n", __FUNCTION__);
}

ChmiProvider::~ChmiProvider() {
    fmt::print("{} destructor\n", __FUNCTION__);
}

// std::shared_ptr<ChmiProvider> ChmiProvider::instance(std::shared_ptr<BasicCfg> cfg) {
//     auto chmiProvider = new ChmiProvider{std::dynamic_pointer_cast<ChmiCfg>(cfg)};  // wyścig
//     static auto contentProvider = std::shared_ptr<ChmiProvider>(chmiProvider);

//     return contentProvider;
// }

void ChmiProvider::fetchContent() {
    fmt::print("ChmiProvider fetchContent\n", __FUNCTION__);
    // auto request = std::make_shared<restbed::Request>(restbed::Uri("http://www.modellzentrale.de/WRF4km/00Z/09h/VV850_eu.png"));
    // request->set_header("Accept", "*/*");
    // request->set_header("Accept-Encoding", "gzip, deflate, br");
    // request->set_header("Connection", "keep-alive");
    // request->set_header("Host", "www.modellzentrale.de");
    // request->set_method("GET");

    // auto settings = std::make_shared<restbed::Settings>();
    // settings->set_follow_redirects(true);

    // restbed::Service service;
    // service.publish(request);

    // auto response = restbed::Http::sync(request);
    // fmt::print("response code: {}\n", response->get_status_code());
}
