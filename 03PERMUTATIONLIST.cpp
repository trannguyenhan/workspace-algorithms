#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, k;
int arr[MAX];
int cnt = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0; i<n; i++)
        arr[i] = i+1; // Cau hinh dau tien

    while(cnt<k){
        int i = n-2;
        while(i>=0 && arr[i] > arr[i+1]) i--;

        if(i<0){
            cout << "-1";
            return 0;
        }

        int j = n-1;
        while(arr[j] < arr[i]) j--;
        swap(arr[j],arr[i]);

        int a = i+1;
        int b = n-1;
        while(a<b){
            swap(arr[a],arr[b]);
            a++;
            b--;
        }
        cnt++;
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
