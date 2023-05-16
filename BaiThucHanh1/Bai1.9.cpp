// Nguyen Van Duy - 20215334
/*
 * Bài 1.9. Viết chương trình in ra tất cả các dãy con của một dãy cho trước.
 */
#include <iostream>

using namespace std;

void process(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        string s;
        for (int j = i; j < n; ++j) {
            s += to_string(a[j]) + " ";
            cout << s << endl;
        }
    }
}

int main() {
    int *a, n;

    // nhap gia tri cho n
    cin >> n;

    // Allocate memory for the array
    a = new int[n];

    // nhap gia tri cho mang
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "out : " << endl;
    process(a, n);

    // free memory
    delete[] a;
}
// Nguyen Van Duy - 20215334
