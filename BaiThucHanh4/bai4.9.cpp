// Nguyen Van Duy - 20215334
/*
Bài 4.9. Cài đặt thuật toán Dijkstra trên đồ thị vô hướng
được biểu diễn bằng danh sách kề sử dụng priority_queue
Cụ thể, bạn cần cài đặt hàm
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj)
nhận đầu vào là danh sách kề chứa các cặp pair<int, int>
biểu diễn đỉnh kề và trọng số tương ứng của cạnh.
Đồ thị gồm n đỉnh được đánh số từ 0 tới n-1.
Hàm cần trả vector<int> chứa n phần tử lần lượt là
khoảng cách đường đi ngắn nhất từ đỉnh 0 tới các đỉnh 0, 1, 2, ..., n-1.
*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************
    # YOUR CODE HERE #
    *****************/

    vector<int> dist(adj.size(), INT_MAX); // result
    dist[0] = 0; // update distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue
    pq.push({0, 0}); // start with 0
    while (!pq.empty()) { // loop
        int u = pq.top().second; // get vertex (u)
        pq.pop(); // remove from top of priority queue
        for (int i = 0; i < adj[u].size(); i++) { // loop through adjacent vertices of current vertex (u)
            int v = adj[u][i].first; // get vertex (v)
            int w = adj[u][i].second; // get weight to the vertex (v)
            if (dist[v] > dist[u] + w) { // check if old distance is greater than new distance
                dist[v] = dist[u] + w; // update distance
                pq.push({dist[v], v}); // recalculate distance from vertex (v)
            }
        }
    }
    return dist;
}

int main() {
    int n = 9;
    vector < vector < pair < int, int > > > adj(n);
    auto add_edge = [&adj](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}
// Nguyen Van Duy - 20215334
