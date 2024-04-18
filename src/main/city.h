//
// Created by Mia Camacho on 4/17/24.
//
#include<string>
#include<vector>


#ifndef PROJECT3_TRANSPARENT_URBAN_LIVING_CITY_H
#define PROJECT3_TRANSPARENT_URBAN_LIVING_CITY_H

using namespace std;

class City {
private:

    string city;
    float lat;
    float lng;
    string country;
    int population;
    string admin_name;
    string capital;


public:

    City(string& city, float lat, float lng, string& country, int population, string& admin_name, string& capital);
    City();
    string getName();
    int getPopulation() const;

};

#endif //PROJECT3_TRANSPARENT_URBAN_LIVING_CITY_H
