// Nguyen Van Duy - 20215334
/*
Bài 4.10. Xây dựng một máy tìm kiếm (search engine) đơn giản.
Cho  N  văn bản và  Q  truy vấn.
Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất.

Sử dụng phương pháp tính điểm TF-IDF
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int n, q;
vector<vector<string>> text_vector; // n texts
vector<vector<string>> query_vector; // q queries
map<pair<string, int>, int> f; // frequency of occurrence of the word @t in the text[i] (pair<string, int>)
vector<int> max_f; // maximum frequency of occurrence in the text[i]
map<string, int> df; // number of text containing the word t

// split string by ','
inline vector<string> split_string(const string &s) {
    vector<string> res; // result
    string t;
    for (char i: s) {
        if (i != ',') {
            t.push_back(i); // add to t or t += i
        } else {
            res.push_back(t); // add t to vector res
            t.clear(); // t = ""
        }
    }
    res.push_back(t); //
    return res; // return result
}

inline void input() {
    cin >> n; // input n
    for (int i = 0; i < n; ++i) {
        string temp; // allocate
        cin >> temp; // get string
        text_vector.push_back(split_string(temp)); // add split string
    }
    cin >> q; // input q
    for (int i = 0; i < q; ++i) {
        string temp; // allocate
        cin >> temp; // get string
        query_vector.push_back(split_string(temp)); // add split string
    }
}

inline void calc_f() {
    for (int i = 0; i < n; ++i) {
        int maximum = 0; // max f
        for (auto &t : text_vector[i]) {
            pair<string, int> key = make_pair(t, i); // key : word @t in text[i]
            if (f.find(key) != f.end()) { // check if key exists
                ++f[key]; // increase f
            } else {
                f[key] = 1; // set f
            }
            maximum = max(maximum, f[key]); // check and update maximum
        }
        max_f.push_back(maximum); // push_back max f to vector
    }
}

inline int calc_df(const string& t) {
    if (df.find(t) != df.end()) { // check if t exists
        return df[t]; // return calculated result
    }
    
    int res = 0; // result
    for (int i = 0; i < n; ++i) {
        for (string &s : text_vector[i]) {
            if (t == s) {
                ++res; // increase 1
                break;
            }
        }
    }
    df[t] = res; // update result
    return res; // return result
}

inline double score(const string& t, int index_text) {
    if (f[{t, index_text}] == 0) return 0; // score = 0
    
    // score = tf * idf
    // trong do :
    //   tf = 0.5 + 0.5 * f / max_f
    //   idf = log2 (N / df)
    return (0.5 + 0.5 * f[{t, index_text}] / max_f[index_text]) * log2(n / calc_df(t));
}

inline int search_engine(vector<string> &queries) {
    int res = -1; // result
    double max_score = -1; // maximum score
    for (int i = 0; i < n; ++i) {
        double score_cur = 0; // current score
        for (auto &t : queries) {
            score_cur += score(t, i); // calculate and increase
        }
        
        if (score_cur > max_score) { // check if max score
            max_score = score_cur; // update max score
            res = i; // update index (result)
        }
    }
    return res + 1; // return
}

int main() {
    input();
    calc_f(); // pre-calc
    for (auto &query : query_vector) {
        cout << search_engine(query) << endl;
    }
    
    return 0;
}

// Nguyen Van Duy - 20215334
