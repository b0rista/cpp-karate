//
//  main.cpp
//  SquareEverything
//
//  Created by Boris Tarovik on 04.07.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template<typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2);

template<typename T>
vector<T> operator*(const vector<T>& v1, const vector<T>& v2);

template<typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& m1, const map<Key, Value>& m2);

template<typename T>
T Sqr(const T& x);


template<typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
    return {p1.first * p2.first, p1.second * p2.second};
}

template<typename T>
vector<T> operator*(const vector<T>& v1, const vector<T>& v2) {
    vector<T> result = v1;
    for (size_t i = 0; i < v1.size(); ++i) {
        result[i] = v1[i] * v2[i];
    }
    return result;
}

template<typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& m1, const map<Key, Value>& m2) {
    map<Key, Value> result;
    for (const auto& item: m1) {
        result[item.first] = item.second * m2.at(item.first);
    }
    return result;
}

template<typename T>
T Sqr(const T& x) {
    return x * x;
}


int main(int argc, const char * argv[]) {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
