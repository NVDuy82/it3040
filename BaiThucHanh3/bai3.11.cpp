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

int n, c[MAX][MAX]; //# số địa điểm và ma trận chi phí
int r;  //# số người với sở thích chụp ảnh khác nhau
int curr; //# tổng khoảng cách tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những địa điểm đã đi
int x[MAX]; //# lưu giữ các địa điểm đã đi

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
    // constructor
    state(int i, int j) : i(i), j(j) {}
};

// o thu tu i, di den dia diem j
// hoac
// xoa dia diem da di o thu tu i, neu j = 0
inline void write(int i, int j) {
    mark[j] = 1; // danh dau da di qua dia diem j
    if (i == 1 && j) {
        // i la dia diem dau tien
        x[i] = j; // luu gia da di dia diem i
        return;
    }
    
    // neu i khong phai dia diem dau tien
    if (j) {
        x[i] = j; // luu gia da di dia diem i
        curr += c[x[i-1]][x[i]]; // cap nhat khoang cach
        return;
    } else {
        // j = 0
        // xoa dia diem da di o thu tu i
        curr -= c[x[i-1]][x[i]]; // xoa khoang cach da di
        mark[x[i]] = 0; // danh dau dia diem chua di
        x[i] = j;
        return;
    }
}

int main() {
    input();
    
    cin.ignore();
    while (r--) {
        string line; // doc noi dung 1 dong
        getline(cin, line);
        
        stringstream ss(line);
        vector<int> v; // luu cac dia diem can di qua
        v.push_back(0);
        
        while (!ss.eof()) {
            int temp;
            ss >> temp; // doc du lieu dia diem
            v.push_back(temp); // luu vao danh sach
        }
        
        stack<state> s;
        memset(mark, 0, sizeof(mark)); // gán giá trị 0 (chưa đi qua) cho tất cả địa điểm
        int best = INT_MAX; //# tổng khoảng cách nhỏ nhất cần tìm
        // ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
        curr = 0; // khoảng cách thời điểm hiện tại ban đầu đặt bằng 0
        bool not_found = true; // trạng thái đã tìm được đường đi hay chưa, ban đầu là chưa
        
        s.emplace(1, v[1]); // đi đến địa điểm đầu tiên trong dach sách
        while (!s.empty()) {
            state &top = s.top();
            int i = top.i, j = top.j;  // luu cac gia tri o ngan dau tien stack
            s.pop();
            
            write(i, j);
            
            // j = 0 thì bỏ qua bước tiếp theo
            if (!j) continue;
            
            if (i == v.size() - 2 && c[j][v.back()]) {
                write(++i, v.back()); // đi đến địa điểm cuối trong danh sách
                if (curr < best) {
                    best = curr; // cập nhất khoảng cách nhỏ nhất
                    not_found = false; // đã tìm thấy ít nhất 1 đường đi
                }
                
                write(i, 0); // xóa địa điểm đi cuối
                // và kiểm tra các phương án khác
                continue;
            }
            
            for (int k = 1; k < v.size() - 1; ++k) {
                if (!mark[v[k]] && c[j][v[k]]) {
                    s.emplace(i+1, 0);  // đưa lệnh xóa đia điểm kế tiếp vào stack
                    s.emplace(i+1, v[k]); // đưa địa điểm chưa đến vào địa điểm kế tiếp
                }
            }
        }
        
        if (not_found) {
            // không tìm được đường đi nào
            cout << 0 << endl;
        } else {
            // in ra khoảng cách nhỏ nhất tìm được
            cout << best << endl;
        }
        
    }
    
    return 0;
}
// Nguyen Van Duy - 20215334
