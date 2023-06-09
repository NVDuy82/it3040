// Nguyen Van Duy - 20215334
/*
Bài 3.9. Một y tá cần lập lịch làm việc trong  N  ngày,
mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi.
Một lịch làm việc là tốt nếu không có hai ngày nghỉ nào
liên tiếp và mọi chuỗi ngày tối đại làm việc liên tiếp
đều có số ngày thuộc đoạn  [K1,K2].
Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch
in ra trên một dòng một xâu nhị phân độ dài  n  với
bit 0/1 tương ứng là nghỉ/làm việc.
Các xâu phải được in ra theo thứ tự từ điển
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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            if (x[n] && top.old_L >= k1 || !x[n]) {
                for (int i = 1; i <= n; ++i)
                    cout << x[i];
                cout << endl;
            }
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
        
        x[i] = j; // ghi trang thai lam viec ngay i
        
        if (j) {
            // case: j = 1
            L = old_L + 1; // so ngay lam viec lien tiep tang them 1
            if (L >= k1) {
                // dua vao stack 1 state (nghi vao ngay tiep theo)
                s.push(state(i + 1, 0, L));
            } else {
                // dua vao stack 1 state (di lam vao ngay tiep theo)
                s.push(state(i + 1, 1, L));
            }
        } else {
            // case: j = 0
            L = 0; // reset so ngay lam viec truoc do
            if (old_L + 1 <= k2) {
                // chuoi ngay lam viec truoc do chua toi da
                // dua vao stack 1 state (di lam vao ngay hien tai)
                s.push(state(i, 1, old_L));
            }
            // dua vao stack 1 state (di lam vao ngay tiep theo)
            s.push(state(i+1, 1, L));
        }
        
    }
    return 0;
}
// Nguyen Van Duy - 20215334

