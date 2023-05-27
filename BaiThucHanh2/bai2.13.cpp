#include <iostream>
#include <cstring>

using namespace std;

inline bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

inline int to_num(char c) {
    return c - '0';
}

inline char * add(char *big, char *small) {
    size_t size = strlen(big) + 1;
    char *s = new char[size+1];
    s[0] = '0';
    strcpy(s+1, big);
    
    int flag = 0;
    for (int i = (int)(size) - 1; i >= 0; --i) {
        if (flag) {
            ++s[i];
        }
        
        int i_sma = i - (int)(size - strlen(small));
        if (i_sma >= 0) {
            s[i] = (char) (s[i] + small[i_sma] - '0');
        }
        
        if (s[i] > '9') {
            s[i] -= 10;
            flag = 1;
        } else {
            flag = 0;
        }
    }
    
    if (s[0] == '0') {
        return s + 1;
    }
    
    return s;
}

inline char * sub(char *big, char *small) {
    size_t size = strlen(big);
    char *s = new char[size+1];
    strcpy(s, big);
    
    int flag = 0;
    for (int i = (int)(size) - 1; i >= 0; --i) {
        if (flag) {
            --s[i];
        }
        
        int i_sma = i - (int)(size - strlen(small));
        if (i_sma >= 0) {
            s[i] = (char) (s[i] - small[i_sma] + '0');
        }
        
        if (s[i] < '0') {
            s[i] += 10;
            flag = -1;
        } else {
            flag = 0;
        }
    }
    
    return s;
}

struct bigNum{
    char sign;
    char num[101]{};

    bigNum() {
        sign = '1';
        num[0] = '0';
        num[1] = '\0';
    }
    
    bigNum(char sign, const char *num) {
        this->sign = sign;
        for (int i = 0; i < 101; ++i) {
            this->num[i] = num[i];
        }
    }
    
    bigNum(long long v) {
        *this = v;
    }
    
    bigNum operator-() const {
        bigNum res = *this;
        res.sign = (char) (97 - sign);
        return res;
    }
    
    bigNum abs() const {
        bigNum res = *this;
        res.sign = '1';
        return res;
    }
    
    bigNum & operator = (const bigNum v) {
        sign = v.sign;
        memcpy(num, v.num, 101);
        return *this;
    }
    
    bigNum & operator = (long long int v) {
        if (v < 0) {
            sign = '0';
            v = -v;
        } else {
            sign = '1';
        }
        
        char temp[100];
        int len = 0;
        for (int i = 0; i < 100 && v; ++i) {
            temp[i] = (char) (v % 10 + '0');
            ++len;
            v /= 10;
        }
        
        this->num[len--] = '\0';
        for (int i = 0; i <= len; ++i) {
            num[len-i] = temp[i];
        }
        
        return *this;
    }

    friend istream & operator >> (istream & is, bigNum & bNum) {
        is >> bNum.sign >> bNum.num;
        return is;
    }

    friend ostream & operator << (ostream & os, bigNum bNum) {
//        if (bNum.sign == '0') {
//            os << "-";
//        }
//        os << bNum.num;
        os << bNum.sign << bNum.num;
        return os;
    }
    
    static inline bool biggerNum(bigNum a, bigNum b) {
        size_t len1 = strlen(a.num);
        size_t len2 = strlen(b.num);
        
        if (len1 > len2) return true;
        if (len1 < len2) return false;
        
        for (int i = 0; i < 101; ++i) {
            if (a.num[i] > b.num[i]) return true;
            if (a.num[i] < b.num[i]) return false;
        }
        
        return false;
    }

    bigNum operator + (bigNum other) {
        bigNum res;
        
        bigNum *big, *small;
        if (biggerNum(*this, other)) {
            big = this;
            small = &other;
        } else {
            big = &other;
            small = this;
        }
        
        res.sign = big->sign;
        if (small->sign == big->sign) {
            strcpy(res.num, add(big->num, small->num));
        } else {
            strcpy(res.num, sub(big->num, small->num));
        }
        
        return res;
    }
    
    bigNum operator - (bigNum other) {
        return *this + (-other);
    }
    
    bigNum operator * (bigNum other) {
        int len_this = (int) strlen(this->num);
        int len_other = (int) strlen(other.num);
        int len = len_this + len_other;
        
        char *temp = new char[len+1];
        temp[len] = '\0';
        
        int flag = 0;
        int last = len - 1;
        int last_this = len_this - 1;
        int last_other = len_other - 1;
        for (int i = 0; i < len; ++i) {
            int calc = flag % 10;
            flag /= 10;
            
            for (int j = 0; j <= i; ++j) {
                if (j < len_this && i-j < len_other) {
                    calc += (this->num[last_this-j] - '0') * (other.num[last_other-(i-j)] - '0');
                }
            }
            
            if (calc > 9) {
                flag += calc / 10;
                calc %= 10;
            }
            
            temp[last - i] = (char) (calc + '0');
        }
        
        return {(this->sign == other.sign) ? '1' : '0', (*temp - '0')  ? temp : temp + 1};
    }
    
    template<class T>
    bigNum operator * (T v) const {
        char sign_res = sign;
        if (v < 0) {
            sign_res = (char) (97 - sign);
            v = -v;
        }
        
        char temp[101];
        int len = (int) strlen(num);
        memset(temp, '0', 101-len-1);
        memcpy(temp+101-len-1, num, len+1);
        
        int flag = 0;
        int i;
        for (i = 99; i >= 0; --i) {
            int calc = (int)(temp[i] - '0') * v + flag % 10;
            flag /= 10;
            
            if (calc > 9) {
                flag += calc / 10;
                calc %= 10;
            }
            
            temp[i] = (char) (calc + '0');

            if (99-i >= len && !calc && !flag) {
                ++i;
                break;
            }
        }
        
        return {sign_res, temp + i};
    }
};

int main() {
    bigNum a, b;
    cin >> a >> b;
    cout << a*b - a*3 + b*4 << endl;
    return 0;
}
