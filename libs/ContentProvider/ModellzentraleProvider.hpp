#pragma once

#include <memory>
#include "ContentProvider.hpp"
#include "ModellzentraleCfg.hpp"

namespace Provider {

class ModellzentraleProvider : public ContentProvider {
public:
    ~ModellzentraleProvider();

    void fetchContent() noexcept;
    ModellzentraleProvider();
    ModellzentraleProvider(const ModellzentraleCfg &cfg);
    ModellzentraleProvider(ModellzentraleProvider& instance) = delete;
private:
};

}
