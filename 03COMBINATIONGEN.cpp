#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, m;
int arr[MAX];

// In ket qua
void printResult(){
    for(int i=0; i<m; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> arr[i];
    }
    //sort(arr,arr+m);

    // Neu khong phai truong hop dac biet gi, tang phan tu foo cung va in ket qua
    int foo = m-1;
    if(arr[foo] != n){
        arr[foo]++;
        printResult();
    } else { // Bat dau xet cac truong hop dac biet, phan tu foo la phan tu lon nhat
        while(arr[foo] - arr[foo-1] == 1) foo--;
        // Tru them 1 lan nua de tim ra vi tri dau tien khong thuoc day lien tiep lon nhat
        // VD : 1 4 5 6 7, vi tri foo la vi tri arr[foo] = 1
        foo--;
        if(foo < 0){
            cout << "-1"; // Neu foo < 0, tuc la cau hinh la cau hinh cuoi, in ra man hinh -1 la ket thuc chuong trinh
            return 0;
        } else {
            arr[foo]++;
            for(int i=foo+1; i<m; i++)
                arr[i] = arr[foo] + i - foo;
            printResult();
        }
    }

    return 0;
}
