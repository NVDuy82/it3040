// Nguyen Van Duy - 20215334
/*
Bài 2.11. Cho 2 đa thức A(x) và B(x) tương ứng có bậc N và M.
Hãy tính ma trận tích C(x) = A(x) * B(x) có bậc N + M.
*/
#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
private:
    int n;
    vector<int> a;

public:
    // no-args constructor
    Polynomial() {
        this->n = 0;
        a.push_back(0);
    }
    
    // Parameterized constructor
    explicit Polynomial(int n) : n(n) {
        for (int i = 0; i <= n; ++i) {
            a.push_back(0);
        }
    }
    
    // Parameterized constructor
    Polynomial(int n, const vector<int> &a) : n(n), a(a) {}

    // return size of vector = N + 1
    [[nodiscard]] size_t size() const {
        return a.size();
    }

    // XOR
    [[nodiscard]] int xor_coefficients() const {
        int res = 0;
        
        for (int i = 0; i < a.size(); ++i) {
            res ^= a[i];
        }
        
        return res;
    }
    
    [[nodiscard]] int getN() const {
        return n;
    }
    
    void clear() {
        n = 0;
        a.clear();
    }

    friend istream & operator >> (istream & is, Polynomial & v) {
        v.clear();
        is >> v.n;
        
        for (int i = 0; i <= v.n; ++i) {
            int temp;
            is >> temp;
            v.a.push_back(temp);
        }
        
        return is;
    }

    friend ostream & operator << (ostream & os, Polynomial v) {
        for (int i = 0; i < v.n; ++i) {
            os << v.a[i] << " ";
        }
        os << v.a[v.n];
        return os;
    }

    // multiplying two polynomials
    Polynomial operator * (const Polynomial & v) const {
        Polynomial res(this->n + v.n);
        
        for (int i = 0; i <= res.n; ++i) {
            
            for (int j = 0; j <= i; ++j) {
                if (j < this->size() && i-j < v.size()) {
                    res.a[res.getN() - i] += this->a[this->getN()-j] * v.a[v.getN()-(i-j)];
                }
            }
            
        }
        
        return res;
    }
};

int main() {
    Polynomial a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << (a*b).xor_coefficients() << endl;

    return 0;
}
// Nguyen Van Duy - 20215334
