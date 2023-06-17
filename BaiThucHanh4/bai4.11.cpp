// Nguyen Van Duy - 20215334
/*
Bài 4.11. Bức tường bao quanh một lâu đài nọ được cấu thành
từ  n  đoạn tường được đánh số từ 1 đến  n .
Quân giặc lên kế hoạch tấn công lâu đài bằng cách gửi  ai
tên giặc đánh vào đoạn tường thứ  i.
Để bảo vệ lâu đài có tất cả  s  lính.

Yêu cầu hãy viết chương trình phân bố lính đứng ở các đoạn
tường sao cho tổng số lính là  s  và tổng số lượng tên giặc
lọt vào lâu đài là nhỏ nhất.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Wall {
private:
    int a; // there are @a members in Army
    int k; // each soldier can repel the attack of @k enemies

public:
    // constructor with no arguments
    Wall() : a(0), k(0) {}
    
    // constructor with arguments : @a, @k
    Wall(int a, int k) : a(a), k(k) {}
    
    [[nodiscard]] int passed() const { return a; }
    
    [[nodiscard]] int getK() const { return k; }
    
    void send_soldier(int numbers = 1) {
        a = max(0, a - numbers * k); // recalculate number of enemies entering
        k = min(k, a); // update @k
    }
    
    friend bool operator<(const Wall &w_1, const Wall &w_2) { return w_1.k < w_2.k; }
    
    friend bool operator>(const Wall &w_1, const Wall &w_2) { return w_1.k > w_2.k; }
    
    friend bool operator<=(const Wall &w_1, const Wall &w_2) { return w_1.k <= w_2.k; }
    
    friend bool operator>=(const Wall &w_1, const Wall &w_2) { return w_1.k >= w_2.k; }
    
    friend istream &operator>>(istream &is, Wall &w) {
        is >> w.a >> w.k; // input @a, @k
        return is; // return stream
    }
    
    friend ostream &operator<<(ostream &os, const Wall w) {
        os << "{a = " << w.a << "; k = " << w.k << "}"; // output
        return os; // return stream
    }
};

// sort_walls : descending order
inline void sort_walls(vector<Wall> &v) { sort(v.begin(), v.end(), greater<>()); }

inline int number_of_enemies_entering(vector<Wall> &v) {
    int count = 0; // counter
    for (auto &w: v) { // loop over each wall
        count += w.passed(); // increment counter
    }
    return count; // return result
}

int main() {
    int n, s; // number of wall, and number of soldier
    cin >> n >> s; // enter @n, @s
    
    vector<Wall> walls(n); // wall list
    for (int i = 0; i < n; i++) {
        cin >> walls[i]; // enter @a, @k of the wall
    }
    
    while (s--) { // send soldiers one by one to the wall
        sort_walls(walls); // descending order : sort from largest to smallest
        walls[0].send_soldier(); // send a soldier to
    }
    
    cout << number_of_enemies_entering(walls) << endl; // output
    
    return 0;
}

// Nguyen Van Duy - 20215334
