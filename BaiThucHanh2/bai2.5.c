// Nguyen Van Duy - 20215334
/*
Bài 2.5. Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức.
*/
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>
using namespace std;
struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    return Complex {a.real + b.real, a.imag + b.imag};
}

Complex operator - (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    return Complex {a.real - b.real, a.imag - b.imag};
}

Complex operator * (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    return Complex {a.real * b.real - a.imag * b.imag, a.imag * b.real + a.real * b.imag};
}

Complex operator / (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    double temp = b.real * b.real + b.imag * b.imag;
    return Complex {(a.real * b.real + a.imag * b.imag) / temp, (a.imag * b.real - a.real * b.imag) / temp};
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-')
    << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}
// Nguyen Van Duy - 20215334
