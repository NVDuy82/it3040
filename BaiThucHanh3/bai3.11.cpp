// Nguyen Van Duy - 20215334
/*
Bài 3.11. Superior là một hòn đảo tuyệt đẹp với  n  địa điểm
chụp ảnh và các đường một chiều nối các điểm chụp ảnh với nhau.
Đoàn khách tham quan có  r  người với sở thích chụp ảnh khác nhau.
Theo đó, mỗi người sẽ đưa ra danh sách các địa điểm mà họ muốn chụp.
Bạn cần giúp mỗi người trong đoàn lập lịch di chuyển sao cho đi qua
các điểm họ yêu cầu đúng một lần, không đi qua điểm nào khác,
bắt đầu tại điểm đầu tiên và kết thúc tại điểm cuối cùng
trong danh sách mà họ đưa ra, và có tổng khoảng cách
đi lại là nhỏ nhất.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <cstring>

using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

int r;

inline void show_curr() {
    cout << "curr : " << curr << endl;
}

//# Đọc dữ liệu vào
inline void input(){
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
}

struct state {
    int i;
    int j;

    state(int i, int j) : i(i), j(j) {}
};

inline void show_x(size_t n) {
    for (int i = 1; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << " <- x[]" << endl;
}

inline void write(int i, int j) {
    mark[j] = 1;
    if (i == 1) {
        x[i] = j;
        return;
    }
    
    if (j) {
        x[i] = j;
        curr += c[x[i-1]][x[i]];
        return;
    } else {
        curr -= c[x[i-1]][x[i]];
        mark[x[i]] = 0;
        x[i] = j;
        return;
    }
}

int main() {
    input();

    cin.ignore();
    while (r--) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        vector<int> v;
        v.push_back(0);
        
        while (!ss.eof()) {
            int temp;
            ss >> temp;
            v.push_back(temp);
        }
        
        stack<state> s;
        memset(mark, 0, sizeof(mark));
        int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
        curr = 0;
        bool not_found = true;
        
        s.emplace(1, v[1]);
        while (!s.empty()) {
            state &top = s.top();
            int i = top.i, j = top.j;
            s.pop();
            
            write(i, j);
//            show_x(v.size());
            
            if (!j) continue;
            
            if (i == v.size() - 2 && c[j][v.back()]) {
                write(++i, v.back());
//                cout << "--";
//                show_x(v.size());
                
//                cout << ">> ";
//                show_x(v.size());
                if (curr < best) {
                    best = curr;
                    not_found = false;
                }
                
                write(i, 0);
//                cout << "--";
//                show_x(v.size());
                continue;
            }
            
            for (int k = 1; k < v.size() - 1; ++k) {
                if (!mark[v[k]] && c[j][v[k]]) {
                    s.emplace(i+1, 0);
                    s.emplace(i+1, v[k]);
                }
            }
        }

        if (not_found) {
            cout << "--> " << 0 << endl << endl << endl;
        } else {
            cout << "--> " << best << endl << endl << endl;
        }
        
    }
    
    return 0;
}
// Nguyen Van Duy - 20215334
