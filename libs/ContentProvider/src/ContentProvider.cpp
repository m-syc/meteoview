#include "ContentProvider.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <curl/curl.h>

#define MIN2SEC (60)
#define MAX_TIMESTAMP_LEN (14)

namespace fs = std::filesystem;
using std::chrono::system_clock;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

void ContentProvider::checkMediaDir(const fs::path &path) {
    // Check if the directory exists
    if (!fs::exists(path)) {
        // Create the directory
        if (fs::create_directories(path)) {
            std::cout << "Directory created: " << path << std::endl;
        } else {
            std::cerr << "Failed to create directory: " << path << std::endl;
        }
    } else {
        std::cout << "Directory already exists: " << path << std::endl;
    }
}

std::deque<std::string> ContentProvider::generateTimestamps(unsigned imgNum, unsigned td) {
    std::deque<std::string> timestamps;
    const auto now = system_clock::now();
    std::time_t t_c = system_clock::to_time_t(now);
    char timepoint[MAX_TIMESTAMP_LEN];

    t_c -= (75 * MIN2SEC); // todo replace with localle offset
    for(auto n = 0; n < imgNum; ++n) {
        t_c -= td * MIN2SEC;
        std::tm *tm = std::localtime(&t_c);
        tm->tm_min -= tm->tm_min % td;
        tm->tm_sec = 0;
        std::strftime(timepoint, MAX_TIMESTAMP_LEN, "%Y%m%d.%H%M", tm);
        // sort timestamps in chronologic order (oldest first)
        timestamps.push_front(std::string(timepoint));
    }

    return timestamps;
}

bool ContentProvider::downloadImage(const fs::path &imgPath, const std::string &url) {
    CURL *curl;
    CURLcode res;
    // "/" operator is overloaded in fs::path to join paths
    std::ofstream ofs(imgPath, std::ios::binary);

    if (!ofs.is_open()) {
        std::cerr << "Failed to open file: " << imgPath << std::endl;
        return false;
    }
    std::cout << url << std::endl;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ofs);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
            return false;
        }
        curl_easy_cleanup(curl);
        ofs.close();
        return true;
    }
    return false;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    std::ofstream* ofs = static_cast<std::ofstream*>(userp);
    size_t totalSize = size * nmemb;
    ofs->write(static_cast<char*>(contents), totalSize);
    return totalSize;
}
