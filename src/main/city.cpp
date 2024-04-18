#include "city.h"


City::City(string& city, float lat, float lng, string& country, int population, string& admin_name, string& capital) {
    this->city = city;
    this->lat = lat;
    this->lng = lng;
    this->country = country;
    this->population = population;
    this->admin_name = admin_name;
    this->capital = capital;
}

City::City() {
    city = "";
    lat = 0.0;
    lng = 0.0;
    country = "";
    population = 0;
    admin_name = "";
    capital = "";
}

string City::getName() {
    return city;
}

int City::getPopulation() const {
    return population;
}
