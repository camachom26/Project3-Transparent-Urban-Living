#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <fstream>
#include <functional>

using namespace std;
struct location_stats {     // https://stackoverflow.com/questions/698345/i-need-to-have-a-key-with-multiple-values-what-datastructure-would-you-recommen
    string town_number;     // What I based this struct off of
    string county;
    string state;
    string income;
    string population;
    string poverty_rate;
    string low_access;

    location_stats(string _town_number, string _state, string _county, string _population, string _poverty_rate, string _income, string _low_access){
        town_number = _town_number;
        state = _state;
        county = _county;
        income = _income;
        population = _population;
        poverty_rate = _poverty_rate;
        low_access = _low_access;
    }
};

#ifndef DSAPROJECT3_LOCATION_STATS_STRUCT_H
#define DSAPROJECT3_LOCATION_STATS_STRUCT_H

#endif //DSAPROJECT3_LOCATION_STATS_STRUCT_H
