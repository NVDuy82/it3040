// Nguyen Van Duy - 20215334
/*
Bài 3.5. Tính  Ckn
*/
#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
    if (k > n) return 0;
    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    long long int giaiThua_n = 1; // = n!
    long long int giaiThua_nk = 1; // = (n-k)!
    long long int giaiThua_k = 1; // = k!

    for (long long int i = 1; i <= n; ++i) {
        giaiThua_n *= i;

        if (i <= n-k) {
            giaiThua_nk *= i;
        }

        if (i <= k) {
            giaiThua_k *= i;
        }
    }

    // binom(n, k) = n! / ((n-k)! * k!)
    return giaiThua_n / (giaiThua_nk * giaiThua_k);
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
// Nguyen Van Duy - 20215334
