/*
    Trong một buổi thi đấu giao hữu giữa 2 game thủ, Chimsedinang và Vanlove đã chơi với nhau rất nhiều “C đấu” (set game) đế chế.
    Mỗi C bao gồm nhiều game đấu, mỗi game đấu chỉ có kết quả thắng thua (không có hoà), khi người đầu tiên đạt đến số trận thắng
    trong C là kk trận, thì C đấu kết thúc và C mới được bắt đầu. Ví dụ, C đấu có k = 3k=3 thì C đấu sẽ kết thúc khi đạt đến một trong các
    tỉ số sau: 3-0, 3-1, 3-2 và ngược lại.

    Sau buổi thi, Chimsedinang có tổng cộng xx trận thắng, còn Vanelove có tổng cộng yy trận thắng. Bạn hãy tính thử xem có thể có tối đa
    bao nhiêu C đấu tất cả hay tình huống ban đầu là không thể xảy ra.

    Chú ý: buổi giao hữu chỉ bao gồm nhiều C đấu đã hoàn thành.
*/
#include<bits/stdc++.h>
using namespace std;
int k, x, y;

void input(){
    cin >> k >> x >> y;
}

void solve(){
    cout << x / k + y / k;
}

int main(){
    input();
    solve();
    return 0;
}
