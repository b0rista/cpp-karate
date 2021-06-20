//
//  main.cpp
//  WorryQueue
//
//  Created by Boris Tarovik on 19.06.2021.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void worry(vector<string>& queue, int i) {
    queue[i] = "worry";
}

void quiet(vector<string>& queue, int i) {
    queue[i] = "quiet";
}

void come(vector<string>& queue, int k) {
    queue.resize((int)queue.size() + k, "quiet");
    
//    if (k < 0) {
//        queue.resize((int)queue.size() + k);
//    }
//    else {
//        for (int i = 0; i < k; ++i) {
//            queue.push_back("quiet");
//        }
//    }
}

int worryCount(vector<string>& queue) {
    return (int)count(queue.begin(), queue.end(), "worry");
    
//    int count = 0;
//    for (auto w : queue) {
//        if (w == "worry") {
//            ++count;
//        }
//    }
//    return count;
}

int main(int argc, const char * argv[]) {
    vector<string> queue;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "WORRY_COUNT") {
            cout << worryCount(queue) << endl;
        }
        else {
            int i;
            cin >> i;
            if (cmd == "WORRY") {
                worry(queue, i);
            }
            else if (cmd == "QUIET") {
                quiet(queue, i);
            }
            else if (cmd == "COME") {
                come(queue, i);
            }
        }
    }
    return 0;
}
