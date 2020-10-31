#include <iostream>

using namespace std;

string inXauNhiPhanTruoc(string str){
    int i = str.length() - 1;

    while(i >=0){
        if(str[i] == '1'){
            str[i] = '0';
            return str;
        } else {
            str[i] = '1';
            i--;
        }
    }
    return str;
}

int main()
{
    int T;
    cin >> T;
    while(T>0){
        string str;
        cin >> str;
        cout << inXauNhiPhanTruoc(str);
        T--;
    }

    return 0;
}
