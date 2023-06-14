// Nguyen Van Duy - 20215334
/*
Bài 3.7. Sử dụng phương pháp khử đệ quy bằng stack,
hãy liệt kê các xâu nhị phân độ dài  n  không có  k  bit 1 nào liên tiếp
*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
            i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/
        
        // luu cac gia tri o ngan dau tien stack
        int i = top.i, j = top.j, old_L = top.old_L;
        s.pop();
        
        x[i] = j; // ghi gia tri j vao vi tri thu i
        
        if (j) {
            // neu j = 1 thi so bit 1 o cuoi day tang them 1
            L = old_L + 1;
        } else {
            // neu j = 0 thi khong co bit 1 nao o cuoi day
            L = 0;
            if (old_L + 1 < k) {
                // dua vao stack 1 state (ghi gia tri 1 vao vi tri thu i)
                // thay the so 0 o vi tri hien tai thanh so 1
                s.push(state(i, 1, old_L));
            }
        }
        
        // dua vao stack 1 state (ghi gia tri 0 vao vi tri thu i+1)
        // vi tri tiep theo se nhan gia tri 0
        s.push(state(i + 1, 0, L));
    }
    return 0;
}
// Nguyen Van Duy - 20215334
