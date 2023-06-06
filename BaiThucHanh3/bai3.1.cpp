// Nguyen Van Duy - 20215334
/*
Bài 3.1. Dãy Lucas được định nghĩa bởi  Ln=Ln−1+Ln−2
và bắt đầu bởi  L0=2,  L1=1.
Viết hàm tính số Lucas thứ  n.
*/
#include <iostream>

using namespace std;

int lucas(int n) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    if (n == 0) return 1;
    if (n == 1) return 2;
    
    return lucas(n-1) + lucas(n-2);
}

int main() {
    cout << lucas(2) << endl;
    return 0;
}
// Nguyen Van Duy - 20215334
