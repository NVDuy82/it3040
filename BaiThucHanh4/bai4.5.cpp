// Nguyen Van Duy - 20215334
/*
Bài 4.5. Viết hàm thực hiện thuật toán DFS không sử dụng đệ quy
trên đồ thị biểu diễn bằng danh sách kề vector< list<int> > .
Đồ thị có n đỉnh được đánh số từ 1 đến n.
Thuật toán DFS xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên
từ trái sang phải trong danh sách kề.
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm
(những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    while (!S.empty()) { // loop
        int u = S.top(); // get top
        S.pop(); // pop from the top of the stack
        if (!visited[u]) { // check if u is not visited
            visited[u] = true; // visit u
            cout << u << endl; // print
            list<int>::iterator it; // iterator
            for (it = adj[u].end(); it-- != adj[u].begin(); ) { // loop through adjacent of u
                if (!visited[*it]) { // check if it is not visited
                    S.push(*it); // push it to stack to visit later
                }
            }
        }
    }
}

int main() {
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);

    return 0;
}
// Nguyen Van Duy - 20215334
