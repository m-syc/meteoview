#include "Sat24Provider.hpp"
#include <fmt/core.h>

Sat24Provider::Sat24Provider() {
    // fmt::print("{} constructor\n", __FUNCTION__);
}

Sat24Provider::Sat24Provider(const Sat24Cfg &cfg) {
    // fmt::print("{} constructor with cfg\n", __FUNCTION__);
}

Sat24Provider::~Sat24Provider() {
    // fmt::print("{} destructor\n", __FUNCTION__);
}

// std::shared_ptr<Sat24Provider> Sat24Provider::instance(std::shared_ptr<BasicCfg> cfg) {
//     auto Sat24Provider = new Sat24Provider{std::dynamic_pointer_cast<ChmiCfg>(cfg)};  // wyścig
//     static auto contentProvider = std::shared_ptr<Sat24Provider>(Sat24Provider);

//     return contentProvider;
// }

void Sat24Provider::fetchContent() {
    fmt::print("Sat24Provider fetchContent\n", __FUNCTION__);

}
