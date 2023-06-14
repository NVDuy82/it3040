// Nguyen Van Duy - 20215334
/*
Bài 3.8. Bạn đang muốn kiểm tra xem một vật cho trước có đúng nặng  M  như người ta nói hay không.
Có một cân thăng bằng và  n quả cân. Quả thứ  i  nặng  mi. Hãy chỉ ra một cách cân thỏa mãn.
Quy cách in ra đã được tích hợp trong mã nguồn dưới.
*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/
        
        // luu cac gia tri o ngan dau tien stack
        int i = top.i, j = top.j;
        s.pop();
        
        // neu truong hop truoc do da tung su dung qua can i
        if (x[i] == 1) {
            // huy bo trang thai truoc do
            sum -= m[i]; // tinh lai sum
        }
        
        x[i] = j; // ghi gia tri j vao vi tri thu i (1 hoac -1)
        
        if (j == 1) {
            // su dung qua can thu i
            sum += m[i];
        } else {
            // j = -1
            // khong su dung qua can i
            s.push(state(i, 1)); // dua vao stack 1 state (su dung qua can i)
        }
        
        // dua vao stack 1 state (khong su dung qua can i)
        s.push(state(i + 1, -1));
    }
    cout << -1;
    
    return 0;
}
// Nguyen Van Duy - 20215334
