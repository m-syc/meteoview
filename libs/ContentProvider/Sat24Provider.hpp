#pragma once

#include <memory>
#include "ContentProvider.hpp"
#include <nlohmann/json.hpp>
#include "Sat24Cfg.hpp"

namespace Provider {

class Sat24Provider : public ContentProvider {
public:
    ~Sat24Provider();

    void fetchContent();
    Sat24Provider();
    Sat24Provider(const Sat24Cfg &cfg);
    Sat24Provider(Sat24Provider& instance) = delete;
private:
};

}
