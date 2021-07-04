//
//  main.cpp
//  GetRef
//
//  Created by Boris Tarovik on 04.07.2021.
//

#include <iostream>
#include <map>
#include <stdexcept>

using namespace std;

template<typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& key) {
    if (m.count(key) > 0) {
        return m.at(key);
    }
    else {
        throw runtime_error("there isn't the key");
    }
}

int main(int argc, const char * argv[]) {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}
