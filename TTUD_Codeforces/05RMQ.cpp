#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
const int MAX_i = 20;

int n;
int a[MAX];
int m;
int start[MAX], en[MAX];
int M[MAX_i][MAX];

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cin >> m;
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        start[i] = tmp1;
        en[i] = tmp2;
    }
}

void pre_processing(){
    for(int i=0; i<n; i++) M[0][i] = i;

    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i+(1<<j)-1 < n; i++){
            if(a[M[j-1][i]] < a[M[j-1][i+(1<<(j-1))]]){
                M[j][i] = M[j-1][i];
            } else {
                M[j][i] = M[j-1][i + (1<<(j-1))];
            }
        }
    }
}

int rmq(int i, int j){
    int k = floor(log2(j-i+1));
    /*
    int k;
    for(k=0; k<n; k++)
        if((1<<k) >= (j-i+1)) break;
    */

    if(a[M[k][i]] <= a[M[k][j-(1<<k)+1]]){
        return a[M[k][i]];
    } else {
        return a[M[k][j-(1<<k)+1]];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    pre_processing();
    int res = 0;
    for(int i=0; i<m; i++){
        res += rmq(start[i], en[i]);
        //cout << rmq(start[i], en[i]) << endl;
    }
    cout << res;

    return 0;
}
