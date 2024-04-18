#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include"graph_implementation.h"

using namespace std;

int main() {

    string filename; //inspired by Geeks for Geeks https://www.geeksforgeeks.org/csv-file-management-using-c/
    cout << "enter the name of the file you want to read" << endl;
    cin >> filename;
    fstream fin;
    fin.open(filename, ios::in);

    vector<string> row;
    vector<City> cities;
    string line, word, temp;

    while(getline(fin, line)) {
        row.clear();
        stringstream s(line);
        City c;
        string name, country, admin_name, capital;
        float lng, lat;
        int polulation;

        while(getline(s, word, ',')) {
            row.push_back(word);
        }
        // string name = row[0] ...



    }

    // import data from csv file
    // add this data to a graph
    // city object for good encapsulation


}
