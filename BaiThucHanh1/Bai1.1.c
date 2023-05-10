// Nguyen Van Duy - 20215334
/*
Bài 1.1. Viết một chương trình C nhập vào 3 số nguyên.
Thiết lập một con trỏ để lần lượt trỏ tới từng số nguyên
và hiển thị kết quả giá trị tham chiếu ngược của con trỏ.
*/
# include <stdio.h>
int main(){
    int x, y, z;
    int* ptr;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    // Nhap 3 so nguyen x, y, z
    
    printf("\nThe three integers are:\n");
    ptr = &x; // Gan dia chi cua x cho ptr
    printf("x = %d\n", *ptr);
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    ptr = &y; // Gan dia chi cua y cho ptr
    printf("y = %d\n", *ptr);
    ptr = &z; // Gan dia chi cua z cho ptr
    printf("z = %d\n", *ptr);
    
    
    return 0;
}
// Nguyen Van Duy - 20215334
