// Nguyen Van Duy - 20215334
/*
Bài 2.4. Viết các hàm tính lập phương của số nguyên và số thực.
*/
#include <stdio.h>
int cube(int x) {
    //# trả về lập phương của x
    /*****************
    # YOUR CODE HERE #
    *****************/
    return x*x*x;
}

//# viết hàm tính lập phương của một số kiểu double
/*****************
# YOUR CODE HERE #
*****************/
double cube(double x) {
    return x*x*x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);

    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));

    return 0;
}
// Nguyen Van Duy - 20215334
