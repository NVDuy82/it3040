// Nguyen Van Duy - 20215334
/*
Bài 4.13. Cho một xâu nhị phân độ dài  n .
Hãy viết chương trình đếm số lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.
*/

#include <iostream>
#include <vector>

using namespace std;

inline unsigned long long int count(string &s) {
    unsigned long long int count = 0; // result
    int n = s.length(); // get length of string
    vector<int> sum(n, 0); // sum[i] : sum from 0 to i
    for (int i = 0; i < s.length(); i++) { // loop through string
        for (int j = 0; j <= i; ++j) { // loop from 0 to i
            sum[j] += s[i] == '1' ? 1 : -1; // +1 if binary 1, -1 if binary 0
            if (sum[j] == 0) { // check if number of 0 == number of 1
                count++; // increment counter
            }
        }
    }
    return count; // return
}

int main() {
    string s; // binary string
    cin >> s; // input binary string
    cout << count(s) << endl; // count substring
    
    return 0;
}

// Nguyen Van Duy - 20215334
