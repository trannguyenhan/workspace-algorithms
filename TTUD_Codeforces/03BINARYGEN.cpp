#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n;
string arr;

// In ket qua
void printResult(){
    for(int i=0; i<n; i++){
        cout << arr[i];
    }
}

int main(){
    cin >> n;
    cin >> arr;

    int foo = n-1;
    while(arr[foo] == '1') foo--;

    if(foo < 0){ // Truong hop day nhi phan la 111.111 la xau nhi phan cuoi cung, khong co xau ke tiep
        cout << "-1";
        return 0;
    } else {
        if(foo == n-1){ // Truong hop nay xet chung voi sau cung duoc, tuy nhien de tranh cac truong hop dac biet nen vay xet rieng
            arr[foo] = '1';
            printResult();
        } else {
            arr[foo] = '1';
            for(int j=foo+1; j<n; j++)
                arr[j] = '0';
            printResult();
        }
    }
    return 0;
}
