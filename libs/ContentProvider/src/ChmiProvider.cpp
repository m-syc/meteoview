#include "ChmiProvider.hpp"
#include <fmt/core.h>
#include <iostream>

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

static const std::string BASE_URL = "https://www.chmi.cz/files/portal/docs/meteo/sat/msg_hrit/img-msg{}-1160x800-{}/msg{}-1160x800.{}.{}.0.jpg";
static const fs::path MEDIA_PATH = "./media/Chmi/";
static const std::map<ChmiCfg::Product, std::string> mapProductNames = {
    {ChmiCfg::PROD_IR, "ir108"},
    {ChmiCfg::PROD_IR_BT, "ir108BT"},
    {ChmiCfg::PROD_VIS_IR, "vis-ir"},
    {ChmiCfg::PROD_WV, "wv062"},
    {ChmiCfg::PROD_Airmass, "airmass"},
    {ChmiCfg::PROD_24H_M, "24M"},
    {ChmiCfg::PROD_NIGHT_M, "night-M"},
};

ChmiProvider::ChmiProvider() {
    // fmt::print("{} constructor\n", __FUNCTION__);
}

ChmiProvider::ChmiProvider(const ChmiCfg &cfg) {
    // fmt::print("{} constructor with cfg\n", __FUNCTION__);
    this->cfg = cfg;
}

ChmiProvider::~ChmiProvider() {
    // fmt::print("{} destructor\n", __FUNCTION__);
}

void ChmiProvider::reloadConfig(const ChmiCfg &cfg) {
    this->cfg = cfg;
}

void ChmiProvider::fetchContent() {
    auto timestamps = generateTimestamps(cfg.imgNum, cfg.td);

    for(auto product : cfg.products) {
        fs::path productDir;

        if(product == ChmiCfg::PROD_INVALID) {
            continue;
        }

        // "/" operator is overloaded in fs::path to join paths
        productDir = MEDIA_PATH / fs::path(mapProductNames.at(product));
        checkMediaDir(productDir);

        for(auto ts : timestamps) {
            std::string url;

            fs::path imgPath = productDir / fs::path(ts + ".jpg");
            url = fmt::format(BASE_URL,
                    cfg.area,
                    mapProductNames.at(product),
                    cfg.area,
                    mapProductNames.at(product),
                    ts);
            if(downloadImage(imgPath, url)) {

            }
        }
    }
    // return
}
