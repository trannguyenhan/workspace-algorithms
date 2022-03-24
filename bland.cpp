/*
Vương quốc BLand là một quốc đảo với n hòn đảo nhỏ, hòn đảo thứ i có vị trí tại tọa độ (xi,yi). Khoảng cách giữa hai đảo i, j được tính bằng công thức ⌊(xi−xj)2+(yi−yj)2−−−−−−−−−−−−−−−−−−√⌋ (làm tròn xuống công thức tính khoảng cách). Người dân ở đây di chuyển giữa các hòn đảo bằng những chiếc thuyền, biết một chiếc thuyền có thể đi khoảng cách tối đa là k trước khi phải dừng lại ở một hòn đảo để tiếp nhiên liệu.

Hãy tìm đường đi từ đảo 1 đến đảo n có tổng khoảng cách nhỏ nhất.

Input
Dòng đầu tiên chứa 2 số n, k (n≤500,k≤109) là số hòn đảo và khoảng cách tối đa thuyền có thể đi được.
Trong n dòng tiếp theo, dòng thứ i chứa 2 số nguyên xi, yi (0≤xi,yi≤20000) là vị trí của hòn đảo thứ i.
Output
Ghi ra một số duy nhất là tổng khoảng cách nhỏ nhất cần tìm. Nếu không thể đi từ đảo 1 đến đảo n ghi ra -1.
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 20000;
int n, k;
pair<int, int> x[MAX];

bool visited[MAX];
int y[MAX];

void input(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        pair<int, int> tmp(tmp1, tmp2);
        x[i] = tmp;
    }

    for(int i=0; i<n; i++){
        visited[i] = false;
    }
}

double distance(pair<int, int> x1, pair<int, int> x2){
    return sqrt((x2.first - x1.first) * (x2.first - x1.first) + (x2.second - x1.second) * (x2.second - x1.second));
}

int check(int a, int i){
    if(visited[i] == true){
        return false;
    }

    return true;
}

double min_value = 100000000000;
int min_y[MAX];

void solution(){
    double min_tmp = 0;
    for(int i=1; i<n; i++){
        min_tmp += distance(x[i], x[i-1]);
    }

    if(min_tmp < min_value){
        min_value = min_tmp;
    }
}

void TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a, i)){
            visited[i] = true;
            y[a] = i;

            if(a == n){
                solution();
            } else {
                TRY(a+1);
            }

            visited[i] = false;
        }
    }
}

int main(){
    input();
    TRY(1);

    cout << min_value << endl;
}
