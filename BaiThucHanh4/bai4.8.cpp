// Nguyen Van Duy - 20215334
/*
Bài 4.8. Viết các hàm thực hiện các phép giao và hợp của hai tập hợp mờ được biểu diễn bằng map.

Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1]
biểu thị độ thuộc của phần tử trong tập hợp,
với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp
và ngược lại độ thuộc bằng 0 nghĩa là phần tử chắc chắn không thuộc trong tập hợp.

Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp,
với độ thuộc mới được tính bằng phép toán min và max của hai độ thuộc.
*/

#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    map<T, double> c; // result
    for (auto it = a.begin(); it != a.end(); ++it) { // loop through elements in the set a
        c[it->first] = it->second; // add element to result
    }
    for (auto it = b.begin(); it != b.end(); ++it) { // loop through elements in the set b
        if (c.find(it->first) == c.end()) { // check if element is not yet in the set
            c[it->first] = it->second; // add element to result
        } else { // if element is already in the set
            c[it->first] = max(c[it->first], it->second); // max equals element
        }
    }
    return c; // return result
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    map<T, double> c; // result
    for (auto it = a.begin(); it != a.end(); ++it) { // loop through elements of in the set a
        if (b.find(it->first) != b.end()) { // check if element is already in the set b
            c[it->first] = min(it->second, b.at(it->first)); // min equals element
        }
    }
    return c; // return result
}

template<class T>
void print_fuzzy_set(std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
// Nguyen Van Duy - 20215334
