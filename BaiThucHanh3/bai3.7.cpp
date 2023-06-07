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
        int i = top.i, j = top.j, old_L = top.old_L;
        s.pop();

        x[i] = j;

        if (j) {
            L = old_L + 1;
        } else {
            L = 0;
            if (old_L + 1 < k) {
                s.push(state(i, 1, old_L));
            }
        }

        s.push(state(i + 1, 0, L));

    }
    return 0;
}
// Nguyen Van Duy - 20215334
