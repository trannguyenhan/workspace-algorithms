#include<bits/stdc++.h>
using namespace std;
const int MAX = 50005;

struct point{
    double x,y;
};

int n;
point a[MAX];

// sort with x or y
bool cmp_x(point p1, point p2){
    return p1.x > p2.x;
}
bool cmp_y(point p1, point p2){
    return p1.y > p2.y;
}

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i].x;
        cin >> a[i].y;
    }
    sort(a,a+n,cmp_x);
}

// caculated distance between point 1 and point 2
double dist(int p1, int p2){
    // formula distance euclid
    double d = sqrt((a[p1].x-a[p2].x)*(a[p1].x-a[p2].x) + (a[p1].y-a[p2].y)*(a[p1].y-a[p2].y));
    return d;
}



int main(){
    input();
}
