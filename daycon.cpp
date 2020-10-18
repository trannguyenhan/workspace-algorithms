#include <iostream>
#include<vector>

using namespace std;

// Khai bao bien toan cuc
const int MAX = 2000; // So phan tu toi da cua mang la 200
int N;
int arr[MAX];
int X[MAX];

// In ket qua
void printResult(){
    for(int i=0; i<N; i++){
        if(arr[i] == 1) cout << X[i] << " ";
    }
    cout << endl;
    return;
}

// Quay lui
void TRY(int a){
    for(int v=0; v<=1; v++){
        arr[a-1] = v;
        if(a == N) printResult();
        else
            TRY(a+1);
    }
    return;
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> X[i];
    }
    TRY(1);
    return 0;
}
