#pragma once

#include "BasicCfg.hpp"
#include <filesystem>
#include <deque>
#include "ImageObj.hpp"

// namespace Provider {

class ContentProvider {
    friend class ContentProviderFactory;
public:
    ContentProvider() {};
    virtual ~ContentProvider() {};
    virtual void fetchContent() = 0;
private:
    // ContentProvider& instance(CfgReader &cfg) = delete;
    std::string name = "";

protected:
    void checkMediaDir(const std::filesystem::path &path);
    std::deque<std::string> generateTimestamps(unsigned imgNum, unsigned td);
    bool downloadImage(const std::filesystem::path &imgPath, const std::string &url);
};

// }
