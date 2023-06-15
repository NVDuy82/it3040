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
#include <algorithm>
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
        if (visited[u] == false) { // check if u is not visited
            visited[u] = true; // visit u
            cout << u << " "; // print
            for (int it : adj[u]) { // loop through adjacent of u
                if (visited[it] == false) { // check if it is not visited
                    S.push(it); // push it to stack to visit later
                }
            }
        }
    }
}

int main() {

}
// Nguyen Van Duy - 20215334
