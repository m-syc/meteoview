#include "MeteoService.hpp"

std::map<MeteoService, std::string_view> services =
{
    {MeteoService::Chmi, "Chmi"},
    {MeteoService::Modellzentrale, "Modellzentrale"}
};

std::map<MeteoService, std::string_view> MeteoServiceName() {
    return services;
}

std::string_view getServiceName(MeteoService service) {
    return services.at(service);
}

MeteoService& operator++(MeteoService &type) {
    auto i = static_cast<unsigned>(type);
    i += 1;
    type = static_cast<MeteoService>(i);
    return type;
}

MeteoService operator++(MeteoService type, int) {
    return ++type;
}

const MeteoService operator*(MeteoService type) {
    return type;
}

MeteoService begin(MeteoService type) {
    return MeteoService::BEGIN;
}

MeteoService end(MeteoService type) {
    return MeteoService::END;
}
