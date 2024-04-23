#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<sstream>
#include<fstream>
#include<utility>
#include<functional>


using namespace std;

struct location_stats {
    string town_number;
    string county;
    string state;
    string income;
    string population;
    string poverty_rate;
    string low_access;

    location_stats(string _town_number, string _state, string _county, string _population, string _poverty_rate, string _income, string _low_access)
            : town_number(move(_town_number)), state(move(_state)), county(move(_county)), population(_population),
              poverty_rate(_poverty_rate), income(_income), low_access(_low_access) {}
};

class CensusData {
private:

    unordered_map<string, vector<location_stats>> counties;

public:
    CensusData() = default;
    void insert(string& key, location_stats value) {
        if(counties.find(key) == counties.end()) {
            counties[key] = {value};
        }
        else {
            counties[key].push_back(value);
        }
    }

    vector<location_stats> getlist(string& key) {
        return counties[key];
    }
    void search(ofstream& low_poverty_low_access_file, ofstream& high_poverty_low_access_file,
                ofstream& low_poverty_no_low_access_file, ofstream& high_poverty_no_low_access_file) {
        for (const auto& county : counties) {
            for (const auto& location : county.second) {
                // Convert population and poverty_rate to numerical values
                int lowAccess = stoi(location.low_access);
                double poverty_rate = stod(location.poverty_rate);

                // Check conditions and categorize locations
                if (poverty_rate < 10 && lowAccess == 1) {
                    // Low Poverty, Low Access
                    low_poverty_low_access_file << location.town_number << ","
                                                << location.county << ","
                                                << location.state << ","
                                                << location.population << ","
                                                << location.poverty_rate << ","
                                                << location.income << ","
                                                << location.low_access << "\n";
                } else if (poverty_rate >= 10 && lowAccess == 1) {
                    // High Poverty, Low Access
                    high_poverty_low_access_file << location.town_number << ","
                                                 << location.county << ","
                                                 << location.state << ","
                                                 << location.population << ","
                                                 << location.poverty_rate << ","
                                                 << location.income << ","
                                                 << location.low_access << "\n";
                } else if (poverty_rate < 10 && lowAccess == 0) {
                    // Low Poverty, No Low Access
                    low_poverty_no_low_access_file << location.town_number << ","
                                                   << location.county << ","
                                                   << location.state << ","
                                                   << location.population << ","
                                                   << location.poverty_rate << ","
                                                   << location.income << ","
                                                   << location.low_access << "\n";
                } else if (poverty_rate >= 10 && lowAccess == 0) {
                    // High Poverty, No Low Access
                    high_poverty_no_low_access_file << location.town_number << ","
                                                    << location.county << ","
                                                    << location.state << ","
                                                    << location.population << ","
                                                    << location.poverty_rate << ","
                                                    << location.income << ","
                                                    << location.low_access << "\n";
                }
            }
        }
    }


};



int main() {


    string filename = "/Users/miacamacho/CLionProjects/Project3-Transparent-Urban-Living/src/graph implementation/output.csv";  // Update file path as needed
    ifstream file(filename);

    CensusData g;  // this object stores a map that links county names to a list of census tracts

    if (!file.is_open()) {
        cerr << "Failed to open the file: " << filename << endl;
        return 1;
    }

    string line;
    string town_number; // Changed to string

    // Process file line by line
    while (getline(file, line)) {
        try {
            stringstream ss(line);
            string token;
            string state, county, income, population, poverty_rate, low_access;

            // Parse each field
            getline(ss, town_number, ','); // Parse town_number as string
            getline(ss, state, ',');
            getline(ss, county, ',');
            getline(ss, population, ',');
            getline(ss, poverty_rate, ',');
            getline(ss, income, ',');
            getline(ss, low_access, ',');

            // Create a location_stats object
            location_stats loc(town_number, state, county, population, poverty_rate, income, low_access);

            // Use line number as key and insert into heap
            g.insert(county, loc);
        } catch (const exception& e) {
            // Log error details and continue processing
            //cerr << "Error on line " << town_number << ": " << e.what() << endl;
        }
    }



    file.close();
    // Open the CSV files for each condition
    ofstream low_poverty_low_access_file("low_poverty_low_access.csv");
    ofstream high_poverty_low_access_file("high_poverty_low_access.csv");
    ofstream low_poverty_no_low_access_file("low_poverty_no_low_access.csv");
    ofstream high_poverty_no_low_access_file("high_poverty_no_low_access.csv");

    ofstream county_file("county_data.csv");
    string county = "Waushara County";
    vector<location_stats> augusta = g.getlist(county);
    for(const auto& l : augusta) {
        county_file << l.town_number << ","
                    << l.county << ","
                    << l.state << ","
                    << l.population << ","
                    << l.poverty_rate << ","
                    << l.income << ","
                    << l.low_access << "\n";
    }

    // Perform search and categorize locations, writing to respective files
    g.search(low_poverty_low_access_file, high_poverty_low_access_file, low_poverty_no_low_access_file, high_poverty_no_low_access_file);

    // Close the CSV files
    county_file.close();
    low_poverty_low_access_file.close();
    high_poverty_low_access_file.close();
    low_poverty_no_low_access_file.close();
    high_poverty_no_low_access_file.close();
    return 0;

}
