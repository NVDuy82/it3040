// Nguyen Van Duy - 20215334
/*
Bài 3.12. Cho đồ thị vô hướng  G, hãy đếm số đường đi
đi qua  k  cạnh và không đi qua đỉnh nào quá một lần.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;
#define MAX 100

int n, k, m; //# số thành phố và ma trận chi phí
int mark[MAX]; //# đánh dấu những thành phố đã đi
vector<int> adj[31];

struct state {
    int i;
    int j;
    
    state(int i, int j) : i(i), j(j) {}
};


//# Đọc dữ liệu vào
inline void input() {
    cin >> n >> k;  // dong 1
    cin >> m;  // dong 2
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

inline void show_adj() {
    for (int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for (auto x: adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

inline void show_mark() {
    cout << ":: ";
    for (int i = 1; i <= n; ++i) {
        cout << mark[i] << " ";
    }
    cout << endl;
}

int __main__() {
    for (auto &i: adj) {
        i.clear();
    }
    input();
    memset(mark, 0, sizeof(mark));
    stack<state> s;
    int count = 0;
    
    for (int i = 1; i <= n; ++i) {
        s.emplace(0, i);
        s.emplace(1, i);
    }
    
    while (!s.empty()) {
        state &top = s.top();
        int i = top.i, j = top.j;
        mark[j] = 1;
//        show_mark();
        s.pop();
        
//        if (i) cout << j << " ";
        
        if (i == 0) {
            mark[j] = 0;
//            show_mark();
            continue;
        } else if (i == k) {
//            cout << s.top().i << s.top().j << endl;
//            cout << endl;
            show_mark();
            ++count;
            continue;
        }
        
        for (int l : adj[j]) {
            if (!mark[l]) {
                s.emplace(0, l);
                s.emplace(i+1, l);
            }
        }
    }
    
    cout << count << endl << endl;
    return 0;
}

int main() {
    for (int i = 0; i < 1; ++i) {
        __main__();
    }
    
    return 0;
}
// Nguyen Van Duy - 20215334
