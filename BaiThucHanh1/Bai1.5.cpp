// Nguyen Van Duy - 20215334
/*
Bài 1.5. Viết hàm trả về con trỏ trỏ tới
giá trị lớn nhất của một mảng các số double.
Nếu mảng rỗng hãy trả về NULL.
*/
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
// Nguyen Van Duy - 20215334
