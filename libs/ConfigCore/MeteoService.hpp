#ifndef _METEO_SERVICE
#define _METEO_SERVICE

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
const MeteoService operator*(MeteoService type);
MeteoService begin(MeteoService type);
MeteoService end(MeteoService type);

#endif /* _METEO_SERVICE */