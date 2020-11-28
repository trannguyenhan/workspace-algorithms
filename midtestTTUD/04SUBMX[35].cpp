#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int n, k;
int a[MAX];
double avg_max = 0.0;

void input(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

double avg(int i, int j){
    int sum = 0;
    for(int k=i; k<=j; k++){
        sum += a[k];
    }

    return (double) sum / (j-i+1);
}

void solve(){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            double tmp = avg(i,j);

            if((tmp > avg_max) && (j-i+1 >= k)) avg_max = tmp;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    printf("%.5lf", avg_max);
    return 0;
}
