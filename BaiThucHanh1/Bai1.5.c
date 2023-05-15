// Nguyen Van Duy - 20215334
/*
Bài 1.5. Viết hàm trả về con trỏ trỏ tới
giá trị lớn nhất của một mảng các số double.
Nếu mảng rỗng hãy trả về NULL.
*/
#include <stdio.h>

double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = 0; i < size; ++i) {
        if (*(a+i) > *max) {
            max = a+i;
        }
    }
    
    return max;
}

int main() {
    double arr[] = {1., 10., 2., -7., 25., 3.};
    double* max = maximum(arr, 6);
    printf("%.0f", *max);
    return 0;
}
// Nguyen Van Duy - 20215334
