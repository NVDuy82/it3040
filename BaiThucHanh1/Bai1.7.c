// Nguyen Van Duy - 20215334
/*
Bài 1.7. Viết chương trình nhập vào một mảng các
số nguyên với số lượng các phần tử nhập từ bàn phím.
Sau đó sắp xếp mảng theo thứ tự tăng dần.
Hiển thị danh sách mảng trước và sau khi sắp xếp.
*/
#include <stdio.h>
#include <stdlib.h>
int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    //#Allocate memory
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    a = (int *) malloc(n * sizeof(int));
    /****************/
    
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    //#Sort array
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (*(a+j) > *(a+j+1)) {
                // swap
                int tmp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = tmp;
            }
        }
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    free(a);
    return 0;
}
// Nguyen Van Duy - 20215334
