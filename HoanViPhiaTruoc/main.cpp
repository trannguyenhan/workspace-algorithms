#include <iostream>
#include<vector>

using namespace std;

// Doi cho
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

// In hoan vi phia truoc
vector<int> hoanViPhiaTruoc(vector<int> hoanvi){
    int a = hoanvi.size()-1;
    while(hoanvi[a-1] < hoanvi[a] && a>0) a--;
    a--; // a la phan tu dau tien khong thuoc day doan cuoi tang

    // Neu hoanvi la hoan vi dau tien -> tra ve hoan vi cuoi
    if (a==0){
        int lens = hoanvi.size();
        for(int i=0; i<lens; i++){
            hoanvi[i] = lens - i;
        }
        return hoanvi;
    }

    // Neu hoanvi khong phai la hoan vi dau tien
    int b = hoanvi.size() - 1;
    while(hoanvi[a] < hoanvi[b]) b--;
    // b la phan tu dau tien cua day doan cuoi tang < a

    // Hoan doi 2 vi tri a va b
    Swap(hoanvi[a],hoanvi[b]);

    // Dao nguoc doan cuoi
    int dau = a + 1;
    int cuoi = hoanvi.size()-1;
    while(dau<cuoi){
        Swap(hoanvi[dau],hoanvi[cuoi]);
        dau++;
        cuoi--;
    }

    return hoanvi;
}

// In
void PrintResult(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T>0){
        int N;
        vector<int> hoanvi;

        cin >> N;
        for(int i=0; i<N; i++){
            int temp;
            cin >> temp;
            hoanvi.push_back(temp);
        }

        hoanvi = hoanViPhiaTruoc(hoanvi);
        PrintResult(hoanvi);

    }

    return 0;
}
