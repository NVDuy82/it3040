// Nguyen Van Duy - 20215334
/*
 * Bài 1.10. Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n,
 * trong đó n nhập từ bàn phím. Sau đó tính tổng và tích của hai ma trận đó
 * và đưa kết quả ra màn hình.
 * Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.
 */
#include <iostream>

using namespace std;

void allocate(int ***mt, int n) {
    // Allocate memory for the matrix
    *mt = new int * [n];
    for (int i = 0; i < n; ++i) {
        (*mt)[i] = new int[n];
    }
}

void input(int **mt, int n) {
    // nhap gia tri cho ma tran
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mt[i][j];
        }
    }
}

void sum(int **mtA, int **mtB, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mtA[i][j] + mtB[i][j] << " ";
        }
        cout << endl;
    }
}

void mul(int **mtA, int **mtB, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = 0;
            for (int k = 0; k < n; ++k) {
                val += mtA[i][k] * mtB[k][j];
            }
            cout << val << " ";
        }
        cout << endl;
    }
}

void free(int **mt, int n){
    // Free memory
    for (int i = 0; i < n; ++i) {
        delete[] mt[i];
    }
    if (n > 0) {
        delete[] mt;
    }
}

int main() {
    int **mtA, **mtB, n;

    // nhap gia tri cho n
    cin >> n;

    // Allocate memory
    allocate(&mtA, n);
    allocate(&mtB, n);

    input(mtA, n);
    input(mtB, n);

    // output
    sum(mtA, mtB, n);
    mul(mtA, mtB, n);

    // free memory
    free(mtA, n);
    free(mtB, n);
}
// Nguyen Van Duy - 20215334
