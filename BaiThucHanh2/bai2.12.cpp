// Nguyen Van Duy - 20215334
/*
Bài 2.12. Hôm nay, cô giáo giao cho An một câu hỏi hóc búa.
Cô cho một danh sách với mỗi phần tử có dạng <key, value> và
yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value.
Nếu 2 phần tử có value giống nhau thì sắp xếp giảm dần theo key.

Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.
*/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<pair<int, int>> list;
    map<int, int> index;

    // input : key and value in line
    for (int i = 0; true; ++i) {
        static string s;
        getline(cin, s);

        if (s.empty()) {
            break;
        } else {
            int key, value;
            stringstream ss(s);
            
            // get key and value
            ss >> key >> value;
            
            if (index.find(key) == index.end()) {
                // key does not exist
                list.emplace_back(key, value);
                index[key] = i;
            } else {
                // key exists
                // update : change value
                list[index[key]] = make_pair(key, value);
                --i;
            }

        }
    }

    // sort by value
    sort(list.begin(), list.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.second > b.second) return true;
        if (a.second < b.second) return false;

        // 2 values are equal
        // sort by key
        return a.first > b.first;
    });

    // display list
    for (auto i : list) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
// Nguyen Van Duy - 20215334
