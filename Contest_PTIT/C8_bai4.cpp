#include <iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

/*Bai toan dua ve tim tong binh phuong nho nhat cua day so khi giam day di k don vi trong bat ki so hang nao,
-> Giai quyet bai toan : Giam di lan luot so lon nhat trong day*/

/*Y tuong : Dua het so ki tu cua chuoi str vao 1 hang doi uu tien, sau do lan luot lay ra
so co do uu tien cao nhat giam di 1 don vi va tra lai vao hang doi uu tien
Vidu : hang doi uu tien co 1 2 2 3 -> lay 3 ra, giam di 1 dua lai vao hang doi uu tien -> 1 2 2 2*/

/*Dem chuoi str co bao nhieu ki tu A, bao nhieu ki tu B, bao nhieu ki tu C,... -> Luu vao 1 vector*/
vector<int> demKiTu(string str){
    vector<int> kitu(26,0);
    int lens = str.length();

    for(int i=0; i<lens; i++){
        kitu[str[i]-65]++;
    }

    return kitu;
}

/*Dua het so ki tu cua chuoi str duoc luu trong vector vao 1 hang doi uu tien*/
priority_queue<int> importPriorityQueue(vector<int> vec){
    priority_queue<int> q;

    for(int i=0; i<vec.size(); i++){
        q.push(vec.at(i));
    }

    return q;
}

/*Gia tri be nhat cua sau khi bo di k ki tu*/
int minString(string str, int k){
    vector<int> demkitu = demKiTu(str);
    priority_queue<int> q = importPriorityQueue(demkitu);

    while(k>0){
        int temp = q.top();
        temp--;

        q.pop(); // Xoa dinh
        q.push(temp);  // Them temp vua roi vao dinh
        // -> giam dinh di 1, sap xep lai hang doi uu tien

        k--;
    }

    int sum = 0;
    while(!q.empty()){
        sum = sum + q.top() * q.top();
        q.pop();
    }

    return sum;
}

void printResult(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;

    while(T>0){
        string str;
        int k;

        cin >> k;
        cin >> str;

        cout << minString(str,k);
        cout << endl;
        T--;
    }

    return 0;
}
