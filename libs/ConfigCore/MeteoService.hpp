#pragma once

#include <type_traits>
#include <map>
#include <string>

enum class MeteoService {
    BEGIN,
    Chmi = BEGIN,
    Modellzentrale,
    // Flymet,
    END
};

std::string_view getServiceName(MeteoService service);
std::map<MeteoService, std::string_view> MeteoServiceName();

MeteoService& operator++(MeteoService &type);
MeteoService operator++(MeteoService type, int);
MeteoService operator*(MeteoService type);
MeteoService begin(MeteoService type);
MeteoService end(MeteoService type);
