#include "heapclass.h"

void search(vector<location_stats>& locations, ofstream& low_poverty_low_access_file, ofstream& high_poverty_low_access_file, ofstream& low_poverty_no_low_access_file, ofstream& high_poverty_no_low_access_file){
    for (const auto& loc : locations) {
        double povertyRate = stod(loc.poverty_rate);
        int lowAccess = stoi(loc.low_access);

        // Categorize locations based on the conditions and write to respective CSV files
        if (povertyRate < 5 && lowAccess == 1) {
            low_poverty_low_access_file << loc.town_number << "," << loc.county << "," << loc.state << "," << loc.population << "," << loc.poverty_rate << "," << loc.income << "," << loc.low_access << endl;
        }
        else if (povertyRate >= 5 && lowAccess == 1) {
            high_poverty_low_access_file << loc.town_number << "," << loc.county << "," << loc.state << "," << loc.population << "," << loc.poverty_rate << "," << loc.income << "," << loc.low_access << endl;
        }
        else if (povertyRate < 5 && lowAccess == 0) {
            low_poverty_no_low_access_file << loc.town_number << "," << loc.county << "," << loc.state << "," << loc.population << "," << loc.poverty_rate << "," << loc.income << "," << loc.low_access << endl;
        }
        else if (povertyRate >= 5 && lowAccess == 0) {
            high_poverty_no_low_access_file << loc.town_number << "," << loc.county << "," << loc.state << "," << loc.population << "," << loc.poverty_rate << "," << loc.income << "," << loc.low_access << endl;
        }
    }
}

void find_town_info(vector<location_stats>& locations, string town_number){
    for (auto& loc : locations){    // Iterate through each location in the vector
        if (loc.town_number == town_number){
            cout << "Town number " << town_number << endl;       //Print the location stats
            cout << "County: " << loc.county << endl;
            cout << "State: " << loc.state << endl;
            cout << "Population: " << loc.population << endl;
            cout << "Poverty rate: " << loc.poverty_rate << "%" << endl;
            cout << "Income: $" << loc.income << endl;
            cout << "Low access: " << loc.low_access << endl;
            return;
        }
    }
}

int main() {
    string filename = "C://Users//chmer//Desktop//output.csv";  // Update file path as needed
    ifstream file(filename);

    MaxHeap heap;
    vector<location_stats> locations;
    string line;
    int line_number = 0; // Initialize line number

    // Process file line by line
    while (getline(file, line)){
        line_number++; // Increment line number for each line
        try{
            stringstream ss(line);
            string token;
            string town_number; // Changed to string
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
            locations.push_back(loc);

            heap.insert(line_number, loc);
        }
        catch (exception e){ //DOES NOT WORK WITHOUT
        }
    }
    find_town_info(locations, "1001020600.00");             //SEARCH FUNCTION
    cout <<endl;
    heap.extractMax();                                                      //VERIFIES IT PARSED WHOLE FILE

    file.close();

    ofstream low_poverty_low_access_file("low_poverty_low_access.csv");    // Open CSV files for each condition
    ofstream high_poverty_low_access_file("high_poverty_low_access.csv");
    ofstream low_poverty_no_low_access_file("low_poverty_no_low_access.csv");
    ofstream high_poverty_no_low_access_file("high_poverty_no_low_access.csv");

    search(locations, low_poverty_low_access_file, high_poverty_low_access_file, low_poverty_no_low_access_file, high_poverty_no_low_access_file);

    low_poverty_low_access_file.close();    // Close CSV files
    high_poverty_low_access_file.close();
    low_poverty_no_low_access_file.close();
    high_poverty_no_low_access_file.close();

    return 0;
}
