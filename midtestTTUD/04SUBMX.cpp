#include<bits/stdc++.h>
using namespace std;
const long long MAX = 10000;
long long n, k;
long long a[MAX];
double avg_max = 0.0;
long long sum[MAX][MAX];
double avg[MAX][MAX];

void input(){
    cin >> n >> k;
    for(long long i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i==j) sum[i][j] = a[i];
            sum[i][j] = sum[i][j-1] + a[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i==j) sum[i][j] = a[i];
            sum[i][j] = sum[i][j-1] + a[j];
        }
    }
}

double avg(long long i, long long j){
    long long sum = 0;
    for(long long k=i; k<=j; k++){
        sum += a[k];
    }
    return (double) sum / (j-i+1);
}

void solve(){
    for(long long i=0; i<n-k; i++){
        for(long long j=i+k-1; j<n; j++){
            if(a[j] < avg_max) continue;
            double tmp = (double)sum[i][j]/(j-i+1);
            if((tmp > avg_max)) avg_max = tmp;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    printf("%.5lf", avg_max);

    //cout << sum[0][3];
    return 0;
}
