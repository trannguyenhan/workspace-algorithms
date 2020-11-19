#include<bits/stdc++.h>
using namespace std;
const int MAX = 10005;
const double PI = atan(1)*4;

int N, F;
int cnt = 1e9;
int radii[MAX];
double S[MAX];
double maxS;

void input(){
    maxS = 0;
    cin >> N >> F;
    for(int i=0; i<N; i++){
        cin >> radii[i];
        S[i] = radii[i] * radii[i] * PI;
        maxS = max(maxS, S[i]);
    }
}

// caculated people
bool cha(double s){
    int sum = 0;
    for(int i=0; i<N; i++){
        sum += floor(S[i]/s);
    }

    return sum > F;
}

double solve(double left, double right){
    double mid = (left + right) / 2.0;
    cnt--;

    if(right - left < 1e-7 || cnt < 0){
        return mid;
    } else {
        if(cha(mid)) return solve(mid, right);
        else return solve(left, mid);
    }
}

int main(){
    int T;
    cin >> T;
    while(T > 0){
        input();
        printf("%.6f\n",solve(0, maxS));
        T--;
    }

}
