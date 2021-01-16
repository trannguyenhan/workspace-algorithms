#include<bits/stdc++.h>
using namespace std;

const int MAX = 200;
int n;
int s[MAX]; // s[i] : chieu cao lon nhat tu block 1 -> block i (tinh ca block i)

// dinh nghia cau truc du lieu
struct block{
    int x, y, z;

    // dinh nghia toan tu < de so sanh 2 block a,b
    bool operator <(block &b){
        return x < b.x && y < b.y;
    }
}b[MAX];

// dinh nghia compare de so sanh 2 block
bool cmp(block &b1, block &b2){
    if(b1.x != b2.x) return b1.x > b2.x;
    if(b1.y != b2.y) return b1.y > b2.y;
    return b1.z > b2.z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 0; // so thu tu cac test case
    do{
        cin >> n;
        if(n == 0) break;
        int m = 0; // so thu tu cua block tiep theo
        cnt++;
        int x[3]; // luu tru cac toa do x, y, z

        // luu cac hoan vi cua 1 block
        for(int i = 1; i <= n; i++){
            cin >> x[0] >> x[1] >> x[2];
            sort(x, x+3);

            // luu cac hoan vi cua block
            do{
                m++;
                b[m].x = x[0]; b[m].y = x[1]; b[m].z = x[2];
            }while(next_permutation(x, x+3)); // ham nay se tra ve cac hoan vi
        }

        // sap xep cac khoi theo chieu giam dan tu block 1 -> m
        sort(b+1, b+m+1, cmp);

        s[1] = b[1].z;
        int ans = s[1];

        // duyet tung block
        for(int i = 2; i <= m; i++){
            s[i] = b[i].z;

            // duyet tu dau den khoi i-1
            for(int j = 1; j <= i-1; j++){
                if(b[i] < b[j]){
                    s[i] = max(s[i], s[j] + b[i].z);
                }
            }
            ans = max(ans, s[i]);
        }

        cout << "Case " << cnt << ": maximum height = " << ans << endl;
    }while(true);

    return 0;
}
