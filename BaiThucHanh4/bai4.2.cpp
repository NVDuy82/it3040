#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    // S = 0.5 * |(x_C - x_A)(y_B - y_A) - (x_B - x_A)(y_C - y_A)|
    return 0.5 * fabs((c.first - a.first)*(b.second - a.second) - (b.first - a.first)*(c.second - a.second));
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
