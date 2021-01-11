#include<bits/stdc++.h>
using namespace std;

/*datastructure disjoint-set*/
long long r[MAX]; // rank
long long p[MAX]; // parent of node

void makeSet(long long x){
    p[x] = x;
    r[x] = 0;
}

void unionSet(long long x, long long y){

    if(r[x] > r[y]){
        p[y] = x;
    } else {
        p[x] = y;
        if(r[x] == r[y]) r[y] += 1;
    }
}

long long findSet(long long x){
    while(p[x] != x){
        x = p[x];
    }
    return p[x];
}
/*end datastructure*/

int main(){

}
