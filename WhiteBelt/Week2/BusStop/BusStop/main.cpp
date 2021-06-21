//
//  main.cpp
//  BusStop
//
//  Created by Boris Tarovik on 21.06.2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    int q;
    cin >> q;
    
    map<string, vector<string>> bus2stop;
    map<string, vector<string>> stop2bus;
    
    while (q > 0) {
        string s;
        cin >> s;
        
        if (s == "NEW_BUS") {
            string bus;
            cin >> bus;
            int stopCount;
            cin >> stopCount;
            while (stopCount > 0) {
                string stop;
                cin >> stop;
                
                stop2bus[stop].push_back(bus);
                bus2stop[bus].push_back(stop);
                
                --stopCount;
            }
        }
        else if (s == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stop2bus.count(stop) == 0) {
                cout << "No stop" << endl;
            }
            else {
                for (auto bus : stop2bus[stop]) {
                    cout << bus << ' ';
                }
                cout << endl;
            }
            
        }
        else if (s == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            
            if (bus2stop.count(bus) == 0) {
                cout << "No bus" << endl;
            }
            else {
                for (auto stop : bus2stop[bus]) {
                    cout << "Stop " << stop << ": ";
                    if (stop2bus[stop].size() == 1) {
                        cout << "no interchange" << endl;
                    }
                    else {
                        for (auto otherBus : stop2bus[stop]) {
                            if (otherBus != bus) {
                                cout << otherBus << ' ';
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
        else if (s == "ALL_BUSES") {
            if (bus2stop.size() == 0) {
                cout << "No buses" << endl;
            }
            for (const auto& item : bus2stop) {
                cout << "Bus " << item.first << ": ";
                for (auto stop : item.second) {
                    cout << stop << ' ';
                }
                cout << endl;
            }
        }
        
        --q;
    }
    return 0;
}
