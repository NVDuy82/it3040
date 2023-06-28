// Nguyen Van Duy - 20215334
/*
Bài 4.13. Cho một xâu nhị phân độ dài  n .
Hãy viết chương trình đếm số lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.
*/

#include <iostream>
#include <map>

using namespace std;

inline int calc(int v) {
    // voi so lan xuat hien chenh lech la v, thi so xau dem duoc la:
    // result = 1 + 2 + 3 + ... + (v-1) = v * (v-1) / 2
    return v * (v-1) / 2;
}

int main() {
    string str;
    cin >> str;
    
    map<int, int> m; // <chenh lech : so lan>
    map<int, int>::iterator it;
    int chenh_lech = 0; // chenh lech = so luong 1 - so luong 0
    
    for (char c : str) {
        if (c == '0') chenh_lech--; // giam 1 neu xuat hien 0
        else chenh_lech++; // tang 1 neu xuat hien 1
        
        it = m.find(chenh_lech);
        if (it != m.end()) { // neu do chenh lech da ton tai
            it->second += 1; // tang so lan xuat hien cua chenh lech
        } else {
            m.insert({chenh_lech, 1});
        }
    }
    
    int res = 0; // result
    for (it = m.begin(); it != m.end() ; ++it) {
        res += calc(it->second);
        if (it->first == 0) res += it->second; // neu chenh lech = 0
    }
    
    cout << res; // print result
    return 0;
}

// Nguyen Van Duy - 20215334
