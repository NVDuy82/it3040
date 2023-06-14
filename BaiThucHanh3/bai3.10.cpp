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

// in ra cac gia tri trong vector<int>
inline void print_sol(const vector<int>& v) {
    for (int i : v) {
        cout << i;
    }
    cout << endl;
}

int main() {
    int t; // so test case
    cin >> t; // nhap so test case
    
    while (t--) {
        int n, h; // do dai xau, va khoang cach Hamming
        cin >> n >> h;
        vector<int> v(n); // luu loi giai xau nhi phan

        // tim loi giai cuoi cung theo thu tu tu dien
        for (int i = 0; i < n; ++i) {
            v[i] = i < h ? 1 : 0;
        }
        
        vector<int> v_end(n); // luu loi giai cuoi cung theo thu tu tu dien
        v_end = v;
        
        do {
            // ket qua ke tiep theo thu tu tu dien
            next_permutation(v.begin(), v.end());
            print_sol(v); // in ra xau ket qua
        } while (v != v_end);
    }
    
    return 0;
}
// Nguyen Van Duy - 20215334
