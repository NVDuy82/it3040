// Nguyen Van Duy - 20215334
/*
Bài 3.10. Khoảng cách Hamming giữa hai xâu cùng độ dài là số
vị trí mà ký tự tại vị trí đó là khác nhau trên hai xâu.
Cho  S  là xâu gồm  n  ký tự 0. Hãy liệt kê tất cả
các xâu nhị phân độ dài  n, có khoảng cách Hamming
với  S  bằng  H.
Các xâu phải được liệt kê theo thứ tự từ điển
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void print_sol(const vector<int>& v) {
    for (int i : v) {
        cout << i;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, h;
        cin >> n >> h;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = i < h ? 1 : 0;
        }
        vector<int> v_end(n);
        v_end = v;
        do {
            next_permutation(v.begin(), v.end());
            print_sol(v);
        } while (v != v_end);
    }
    
    return 0;
}
// Nguyen Van Duy - 20215334
