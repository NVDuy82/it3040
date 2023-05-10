// Nguyen Van Duy - 20215334
/*
Bài 1.4. Viết hàm countEven(int*, int)
nhận một mảng số nguyên và kích thước của mảng,
trả về số lượng số chẵn trong mảng???
*/
int counteven(int* arr, int size){
    int count = 0;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = 0; i < size; ++i) {
        if (!(arr[i] & 1)) {
            ++count;
        }
    }
    
    return count;    
}
// Nguyen Van Duy - 20215334
