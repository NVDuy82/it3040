// Nguyen Van Duy - 20215334
/*
Bài 4.3. Một vector trong không gian 3 chiều được biểu diễn bằng tuple<double, double, double>.
Hãy viết hàm Vector cross_product(Vector a, Vector b) tính tích có hướng của 2 vector.
Trong đó Vector là kiểu dữ liệu được định nghĩa sẵn trong trình chấm như sau:
using Vector = tuple<double, double, double>;
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    // res_X = a_Y * b_Z - a_Z * b_Y
    // res_Y = a_Z * b_X - a_X * b_Z
    // res_Z = a_X * b_Y - a_Y * b_X
    return make_tuple(get<1>(a) * get<2>(b) - get<2>(a) * get<1>(b),
                      get<2>(a) * get<0>(b) - get<0>(a) * get<2>(b),
                      get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b));
}

int main() {
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
// Nguyen Van Duy - 20215334
