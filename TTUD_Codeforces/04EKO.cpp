#include<bits/stdc++.h>
using namespace std;
const long long  MAX = 1000000;

long long  N, M;
long long  height[MAX];
long long  maxHeight;

void input(){
    cin >> N >> M;
    maxHeight = 0;
    for(long long  i=0; i<N; i++){
        cin >> height[i];
        maxHeight = max(maxHeight,height[i]);
    }
}

// caculated meter of wood in total
long long  totalMeterWood(long long  cut){
    long long  sum = 0;
    for(long long  i=0; i<N; i++){
        long long  tmp = height[i] - cut;
        if(tmp < 0) tmp = 0;
        sum += tmp;
    }
    return sum;
}

long long  solve(long long  left, long long  right){
    long long  mid = (left + right) / 2;
    long long  total = totalMeterWood(mid);

    if(right - left == 1 || total == M){
        return mid;
    } else {
        if(total < M) return solve(left,mid);
        else return solve(mid,right);
    }
}

int  main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    cout << solve(0,maxHeight);
}
