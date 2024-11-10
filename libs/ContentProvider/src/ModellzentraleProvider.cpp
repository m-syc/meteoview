#include "ModellzentraleProvider.hpp"
#include <fmt/core.h>
#include <restbed>

ModellzentraleProvider::ModellzentraleProvider() {
    fmt::print("{} constructor\n", __FUNCTION__);
}

ModellzentraleProvider::ModellzentraleProvider(const ModellzentraleCfg &cfg) {
    fmt::print("{} constructor with cfg\n", __FUNCTION__);
}

ModellzentraleProvider::~ModellzentraleProvider() {
    fmt::print("{} destructor\n", __FUNCTION__);
}

void ModellzentraleProvider::fetchContent() noexcept {
    fmt::print("ModellzentraleProvider fetchContent\n", __FUNCTION__);
    // auto request = std::make_shared<restbed::Request>(restbed::Uri("http://www.example.com"));
    // request->set_header("Accept", "*/*");
    // request->set_header("Host", "www.example.com");

    // auto response = restbed::Http::sync(request);
    // fmt::print("response code: {}\n", response->get_status_code());
}
