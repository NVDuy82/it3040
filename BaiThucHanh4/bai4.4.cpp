// Nguyen Van Duy - 20215334
/*
Bài 4.4. Cho hai vector, hãy xóa hết các phần tử chẵn,
sắp xếp giảm dần các số trong cả 2 vector và
trộn lại thành một vector cũng được sắp xếp giảm dần.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    for (size_t i = 0; i < a.size(); i++) { // loop
        if (a[i] % 2 == 0) { // check even numbers
            a.erase(a.begin() + i); // remove
            i--; // decrement to keep index
        }
    }
}

void sort_decrease(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    sort(a.begin(), a.end(), [] (int a, int b) -> bool {
        return a >= b; // stable sort by ascending order
    });
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    // merge 2 sorted vectors, return sorted vector
    vector<int> c; // result
    size_t i = 0, j = 0; // index
    while (i < a.size() && j < b.size()) { // loop until a ends or b ends
        // add smaller element
        if (a[i] > b[j]) {
            c.push_back(a[i]);
            i++; // increment index of vector a
        } else {
            c.push_back(b[j]);
            j++; // increment index of vector b
        }
    }
    while (i < a.size()) {
        c.push_back(a[i]); // add the remaining elements of the vector a
        i++;
    }
    while (j < b.size()) {
        c.push_back(b[j]); // add the remaining elements of the vector b
        j++;
    }
    return c; // return
}

int main() {
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
// Nguyen Van Duy - 20215334
