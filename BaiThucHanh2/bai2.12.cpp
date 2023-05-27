#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<pair<int, int>> list;
    map<int, int> index;

    for (int i = 0; true; ++i) {
        static string s;
        getline(cin, s);

        if (s.empty()) {
            break;
        } else {
            int key, value;
            stringstream ss(s);
            ss >> key >> value;
            if (index.find(key) == index.end()) {
                list.emplace_back(key, value);
                index[key] = i;
            } else {
                list[index[key]] = make_pair(key, value);
                --i;
            }

        }
    }

    sort(list.begin(), list.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.second > b.second) return true;
        if (a.second < b.second) return false;

        return a.first > b.first;
    });

    for (auto i : list) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
