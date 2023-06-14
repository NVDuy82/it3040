// Nguyen Van Duy - 20215334
/*
Bài 3.6. Tính ước chung lớn nhất của hai số cho trước
*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    
    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    // lap den khi a = 0 hoac b = 0
    while(a && b) {
        // so lon = so lon % so be
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    
    // tra ve so khac 0 trong hai so a va b
    return a ? a : b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
// Nguyen Van Duy - 20215334
