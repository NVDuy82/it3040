// Nguyen Van Duy - 20215334
/*
Bài 4.12. Cho một lược đồ gồm  n  cột chữ nhật liên tiếp nhau
có chiều rộng bằng 1 và chiều cao lần lượt là các số nguyên
không âm  h1,h2,…,hn.
Hãy xác định hình chữ nhật có diện tích lớn nhất có thể tạo thành từ các cột liên tiếp.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct rectangle {
    int height;
    int width;
    
    rectangle() : height(0), width(0) {}
    
    rectangle(int height, int width) : height(height), width(width) {}
    
    rectangle increment(bool increment_height = false, bool increment_width = true) {
        if (increment_height) { // check if increment height or not
            height++; // increment height
        }
        if (increment_width) { // check if increment width or not
            width++; // increment width
        }
        return *this; // return rectangle
    }
    
    rectangle decrement(bool decrement_height = false, bool decrement_width = true) {
        if (decrement_height) { // check if decrement height or not
            height--; // decrement height
        }
        if (decrement_width) { // check if decrement width or not
            width--; // decrement width
        }
        return *this; // return rectangle
    }
    
    friend rectangle operator++(rectangle &rect) { return rect.increment(); }
    
    friend const rectangle operator++(rectangle &rect, int) {
        rectangle temp = rect; // copy old rectangle
        rect.increment(); // increment rectangle
        return temp; // return old rectangle
    }
    
    friend rectangle operator--(rectangle &rect) { return rect.decrement(); }
    
    friend rectangle operator--(rectangle &rect, int) {
        rectangle temp = rect; // copy old rectangle
        rect.decrement(); // decrement rectangle
        return temp; // return old rectangle
    }
    
    friend rectangle operator+(rectangle &rect, int v) {
        return {rect.height, rect.width + v};
    }
    
    friend void operator+=(rectangle &rect, int v) {
        rect.width += v;
    }
    
    friend ostream &operator<<(ostream &os, rectangle rect) {
        // output : (height x width)
        os << "(" << rect.height << " x " << rect.width << ")";
        return os; // return stream
    }
    
    friend istream &operator>>(istream &is, rectangle &rect) {
        is >> rect.height; // input : height
        rect.width = 0; // set width = 0
        return is; // return stream
    }
    
    [[nodiscard]] int superficie() const {
        return height * width; // area(superficie) = height * width
    }
};

int main() {
    int n; // number of columns
    int res = INT_MIN; // reslut : largest area(superficie), set to INT_MIN
    cin >> n; // input n
    
    vector<rectangle> v(n); // rectangles, whose height corresponds to height of columns
    queue<rectangle> q, old_queue, new_queue;
    // q : contains original rectangles
    // old_queue : (current_queue) contains current rectangles
    // new_queue : (next_queue) contains next rectangles
    
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // input rectangles
        q.push(v[i]); // push into q (original rectangles)
    }
    
    while (!q.empty()) {
        rectangle rect = q.front(); // get 1 of original rectangles
        q.pop(); // remove from q (original rectangles)
        
        while (!old_queue.empty()) { // loop
            rectangle old_rect = old_queue.front(); // get from old queue
            old_queue.pop(); // remove an element from old queue
            
            if (old_rect.height < rect.height) { // check if
                new_queue.push(++old_rect); // rectangle extension and push into next queue
            } else {
                rect.width = max(rect.width, old_rect.width); // update for original rectangle
                res = max(res, old_rect.superficie()); // update largest rectangle
            }
        }
        
        old_queue.swap(new_queue); // switch to next queue
        old_queue.push(++rect); // push original rectangle into current queue
    }
    
    while (!old_queue.empty()) { // loop remaining rectangle
        rectangle old_rect = old_queue.front(); // get rectangle
        old_queue.pop(); // remove from queue
        res = max(res, old_rect.superficie()); // update remaining rectangle
    }
    
    cout << res; // print result
    return 0;
}

// Nguyen Van Duy - 20215334
