//
//  main.cpp
//  Incognizable
//
//  Created by Boris Tarovik on 25.06.2021.
//

#include <iostream>

struct Incognizable {
    int a = 0;
    int b = 0;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
