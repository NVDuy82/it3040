// Nguyen Van Duy - 20215334
/*
Bài 1.2. Viet chuong trinh in ra dia chi cua 5 phan tu dau tien
trong mang duoc dinh nghia sau day:
int a[7]= {13, -355, 235, 47, 67, 943, 1222};
*/
#include <stdio.h>
int main() {
	int a[7]= {13, -355, 235, 47, 67, 943, 1222};
	printf("Nguyen Van Duy - 20215334\n\n");
	printf("Address of first five elements in memory:\n");
	for (int i = 0; i < 5; ++i) {
		printf("\t            a[%d]", i);
	}
	printf("\n");
	for (int i = 0; i < 5; ++i) {
		printf("\t%p", &a[i]);
	}
	
	return 0;
}
// Nguyen Van Duy - 20215334
