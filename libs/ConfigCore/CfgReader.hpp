#ifndef _CFG_REDER
#define _CFG_REDER

#include <filesystem>
#include <vector>
#include "MeteoService.hpp"
#include "BasicCfg.hpp"

struct CfgReader {
    CfgReader() = delete;
    CfgReader(std::filesystem::path cfgPath) noexcept;
    ~CfgReader();

    std::shared_ptr<BasicCfg> get(MeteoService type) noexcept;

private:
    std::filesystem::path cfgPath;
    std::map<MeteoService, std::shared_ptr<BasicCfg>> serviceCfgs;
};

#endif /* _CFG_REDER */