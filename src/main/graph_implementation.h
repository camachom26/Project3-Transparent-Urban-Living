#include <unordered_map>
#include "city.h"

#ifndef PROJECT3_TRANSPARENT_URBAN_LIVING_GRAPH_IMPLEMENTATION_H
#define PROJECT3_TRANSPARENT_URBAN_LIVING_GRAPH_IMPLEMENTATION_H

using namespace std;

class Graph {
private:

    unordered_map<string, vector<pair<string, int>>> cities;
    unordered_map<string, City> key;

public:
    void insert();
    void remove();
    int get_distance();
    vector<pair<City, int>> getAdjlist(string city_name);

};


#endif //PROJECT3_TRANSPARENT_URBAN_LIVING_GRAPH_IMPLEMENTATION_H
