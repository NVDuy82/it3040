// Nguyen Van Duy - 20215334
/*
Bài 1.6. Viết hàm đảo ngược một mảng
các số nguyên theo hai cách:
dùng chỉ số và dùng con trỏ.
*/
void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (l < r) {
        // swap
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        ++l;
        --r;
    }
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (l < r) {
        // swap
        tmp = *(arr+l);
        *(arr+l) = *(arr+r);
        *(arr+r) = tmp;
        ++l;
        --r;
    }
}

// Nguyen Van Duy - 20215334
