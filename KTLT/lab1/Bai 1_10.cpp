#include<bits/stdc++.h>
using namespace std;

int main(){
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int n;
    int **mt1, **mt2;

    cin >> n;

    // Cap phat bo nho cho mt1, mt2
    mt1 = new int*[n];
    mt2 = new int*[n];
    for(int i=0; i<n; i++){
        mt1[i] = new int[n];
        mt2[i] = new int[n];
    }

    // Nhap gia tri cho mt1, mt2
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> mt1[i][j];
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> mt2[i][j];
        }

    // Tinh va in va tong cua 2 ma tran
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            temp = mt1[i][j] + mt2[i][j];
            cout << temp << " ";
        }
        cout << endl;
    }

    // Tinh va in ra tich cua 2 ma tran
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp = 0;
            for(int k=0; k<n; k++){
                temp += mt1[i][k]*mt2[k][j];
            }
            cout << temp << " ";
        }
        cout << endl;
    }
}
