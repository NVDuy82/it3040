// Nguyen Van Duy - 20215334
/*
Bài 4.6. Viết hàm thực hiện thuật toán BFS không sử dụng đệ quy
trên đồ thị biểu diễn bằng danh sách kề vector< list<int> > .
Đồ thị có n đỉnh được đánh số từ 1 đến n.
Thuật toán BFS xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên
từ trái sang phải trong danh sách kề.
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm
(những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    visited[1] = true; // mark 1
    while (!Q.empty()) { // loop
        int u = Q.front(); // get first
        Q.pop(); // remove an element from the front of the queue
        cout << u << endl; // print
        for (auto v : adj[u]) { // loop through adjacent of u
            if (!visited[v]) { // check if it is not visited
                Q.push(v); // push it to queue to visit later
                visited[v] = true; // visit v
            }
        }
    }
}

// Nguyen Van Duy - 20215334
