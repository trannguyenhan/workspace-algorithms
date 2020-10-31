#include <iostream>
using namespace std;

int** capphat(int n, int m){
    int **mt;
    mt = new int *[n];
    for(int i=0; i<n; i++){
        mt[i] = new int[m];
    }
    mt[n-1][m-1] = 1;
    return mt;
}

void capphat(int **mt, int n, int m){
    mt = new int *[n];
    for(int i=0; i<n; i++){
        mt[i] = new int[m];
    }
    mt[n-1][m-1] = 1;
}

void capphat(int **&mt, int n, int m, bool kt){
    mt = new int *[n];
    for(int i=0; i<n; i++){
        mt[i] = new int[m];
    }
    mt[n-1][m-1] = 1;
}

int main()
{
    int **mt;
    capphat(mt,10,9,true);
    cout << mt[9][8];
    return 0;
}
