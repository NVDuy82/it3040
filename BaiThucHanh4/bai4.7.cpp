// Nguyen Van Duy - 20215334
/*
Bài 4.7. Viết các hàm thực hiện các phép giao
và hợp của hai tập hợp được biểu diễn bằng set.
*/
#include <iostream>
#include <set>

using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    set<T> c; // result
    for (auto x : a) { // for each element in the set<T> a
        c.insert(x); // insert to result
    }
    for (auto x : b) { // for each element in the set<T> b
        c.insert(x); // insert to result
    }
    return c; // return result
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    set<T> c; // result
    for (auto x : a) { // for each element in the set<T> a
        if (b.find(x) != b.end()) { // check if the element is already in the set<T> b
            c.insert(x); // add it to the set<T> c (result)
        }
    }
    return c; // return result
}

template<class T>
void print_set(const std::set<T> &a) {
     for (const T &x : a) {
         std::cout << x << ' ';
     }
     std::cout << std::endl;
}

int main() {
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);

    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);

    return 0;
}
// Nguyen Van Duy - 20215334
