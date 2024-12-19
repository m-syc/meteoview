#ifndef __IMAGEOBJ
#define __IMAGEOBJ

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

struct ImageObj {
    fs::path filePath;
    std::string serverName;
    std::string meteoProduct;
    std::string timestamp;
};

#endif /* __IMAGEOBJ */