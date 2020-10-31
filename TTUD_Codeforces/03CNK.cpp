#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n,m,k;
int arr[MAX];
int cnt;

// In ket qua
void printResult(){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void solve(){
    cin >> n >> k >> m;
    for(int i=0; i<k; i++){
        arr[i] = i+1;
    }

    cnt = 1;

    while(k>0){
        // Neu khong phai truong hop dac biet gi, tang phan tu foo cung va in ket qua
        int foo = k-1;
        if(arr[foo] != n){
            arr[foo]++;
        } else { // Bat dau xet cac truong hop dac biet, phan tu foo la phan tu lon nhat
            while(arr[foo] - arr[foo-1] == 1) foo--;
            // Tru them 1 lan nua de tim ra vi tri dau tien khong thuoc day lien tiep lon nhat
            // VD : 1 4 5 6 7, vi tri foo la vi tri arr[foo] = 1
            foo--;
            if(foo < 0){
                break;
            } else {
                arr[foo]++;
                for(int i=foo+1; i<k; i++)
                    arr[i] = arr[foo] + i - foo;
            }
        }
        cnt++;
        //printResult();
        //cout << endl;
    }

    //printResult();
}

int main(){
    int T;
    cin >> T;
    while(T>0){
        solve();
        cout << cnt % m<< endl;
        T--;
    }
    return 0;
}
