//
//  main.cpp
//  CapitalCatalog
//
//  Created by Boris Tarovik on 20.06.2021.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    map<string, string> catalog;
    
    int q;
    cin >> q;
    
    while (q > 0) {
        string s;
        cin >> s;
        if (s == "CHANGE_CAPITAL") {
            string country, newCapital;
            cin >> country >> newCapital;
            
            string oldCapital = catalog[country];
            if (oldCapital.size() == 0) {
                cout << "Introduce new country " << country << " with capital " << newCapital << endl;
                catalog[country] = newCapital;
            }
            else if (oldCapital == newCapital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            }
            else {
                cout << "Country " << country << " has changed its capital from " << oldCapital << " to " << newCapital << endl;
                catalog[country] = newCapital;
            }
        }
        else if (s == "RENAME") {
            string oldCountryName, newCountryName;
            cin >> oldCountryName >> newCountryName;
            if (catalog.count(oldCountryName) == 0 || oldCountryName == newCountryName
                || catalog.count(newCountryName) > 0) {
                cout << "Incorrect rename, skip" << endl;
            }
            else {
                string capital = catalog[oldCountryName];
                catalog.erase(oldCountryName);
                catalog[newCountryName] = capital;
                cout << "Country " << oldCountryName << " with capital " << capital;
                cout << " has been renamed to " << newCountryName << endl;
            }
        }
        else if (s == "ABOUT") {
            string country;
            cin >> country;
            if (catalog.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else {
                cout << "Country " << country << " has capital " << catalog[country] << endl;
            }
        }
        else if (s == "DUMP") {
            if (catalog.size() == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (const auto& el : catalog) {
                    cout << el.first << '/' << el.second << endl;
                }
            }
        }
        --q;
    }
    
    
    return 0;
}
