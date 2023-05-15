// Nguyen Van Duy - 20215334
/*
Bài 1.6. Viết hàm đảo ngược một mảng
các số nguyên theo hai cách:
dùng chỉ số và dùng con trỏ.
*/
#include <iostream>

using namespace std;

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

int main() {
    int arr[] = {9, 3, 5, 6, 2, 5};
    reversearray(arr, 6);
    for(int i = 0; i < 6; i++) cout << arr[i] << " ";
    int arr2[] = {4, -1, 5, 9};
    ptr_reversearray(arr2, 4);
    for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
    return 0;
}
// Nguyen Van Duy - 20215334
