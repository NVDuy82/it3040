// Nguyen Van Duy - 20215334
/*
Bài 5.7. Chia tiền
Sau đại dịch, thầy trò Đường Tăng muốn xin tiền của các nhà giàu để chia cho các nhà nghèo.
Họ sẽ vào n thôn, thôn thứ i có ki nhà. Mỗi thôn họ sẽ quyết định xin tiền hay cho tiền,
phụ thuộc vào đánh giá của họ về mức độ giàu nghèo ở đây. Nếu thôn i giàu, họ sẽ đi từng
nhà trong số ki nhà này và xin ai,j tiền của nhà thứ j. Nếu thôn i nghèo, họ sẽ đi từng
nhà trong số ki nhà này và phát ai,j tiền cho nhà thứ j. Hãy tính số tiền ít nhất họ phải
mang theo để đảm bảo có thể phát đủ cho người nghèo (tức số tiền luôn không bị âm)
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;
        if(t == 1){
            while(k--){
                int a;
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        } else {
            while(k--){
                int a;
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }
    cout << ans;
}
// Nguyen Van Duy - 20215334
