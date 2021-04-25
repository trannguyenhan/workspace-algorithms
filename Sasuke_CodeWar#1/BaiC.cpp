#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<sstream>

using namespace std;

/*Thuat toan kiem tra SNT qua cham -> can cai tien de thuat toan chay nhanh hon nua*/
/*Dao nguoc so*/
int daoSo(int a){
    string str;
    ostringstream ostream;
    ostream << a;
    str = ostream.str();

    string strResult;
    for(int i=str.length()-1; i>=0; i--){
        strResult.push_back(str[i]);
    }

    int b;
    stringstream sstream(strResult);
    sstream >> b;

    return b;
}

/*Ham kiem tra so nguyen to*/
bool ktraNT(int a){
    if(a<2) return false;
    else {
        if(a==2) return true;
        else {
            if(a%2 == 0) return false;
            else {
                for(int i=3; i*i <= a; i=i+2)
                    if(a%i == 0) return false;
            }
        }
    }
    return true;
}

vector<int> reversePrime(int L, int R){
    vector<int> c;
    for(int i=L; i<=R; i++){
        int temp = daoSo(i);
        if(i % 10 !=0){ // Cai nay khong biet duoc -> phan dap an thay the
            if(ktraNT(temp)) c.push_back(i);
        }
    }

    return c;
}

int main()
{
    int a;
    cin >> a;
    cout << daoSo(a);
    return 0;
}
