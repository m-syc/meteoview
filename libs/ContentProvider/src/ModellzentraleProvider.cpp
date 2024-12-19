#include "ModellzentraleProvider.hpp"
#include <fmt/core.h>

ModellzentraleProvider::ModellzentraleProvider() {
    // fmt::print("{} constructor\n", __FUNCTION__);
}

ModellzentraleProvider::ModellzentraleProvider(const ModellzentraleCfg &cfg) {
    // fmt::print("{} constructor with cfg\n", __FUNCTION__);
}

ModellzentraleProvider::~ModellzentraleProvider() {
    // fmt::print("{} destructor\n", __FUNCTION__);
}

void ModellzentraleProvider::fetchContent() noexcept {
    fmt::print("ModellzentraleProvider fetchContent\n", __FUNCTION__);

}
