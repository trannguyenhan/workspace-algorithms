#include <iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

/*Y tuong : Tim so BDN lon nhat khong qua N -> la 1 so nhi phan
-> Chuyen so BDN vua tim duoc ve dang so thap phan -> day chinh la so cac so BDN be hon N*/

/*Do du lieu lon (2^63)-> khong dung "long long" ma luu tru so thanh chuoi (string)
-> giup giam bot bo nho can luu tru*/

/*Tim so BDN lon nhat khong qua so str*/
string findMaxBDN(string str){
    int i = 0;
    int lens = str.length();

    while(i<lens){
        if(str.at(i) > '1'){
            for(int j=i; j<lens; j++)
                str.at(j) = '1';
            return str;
        } else {
            i++;
        }
    }

    return str;
}

/*Chuyen tu so nhi phan sang so thap phan*/
int convertBinToDec(string str){
    int sum = 0;
    int lens = str.length();

    for(int i=0; i<lens; i++){
        if(str.at(i) == '1'){
            sum = sum + pow(2,lens-1-i);
        }
    }

    return sum;
}

int main()
{
    int T;
    cin >> T;

    while(T>0){
        string str;
        cin >> str;

        string maxBDN = findMaxBDN(str);
        cout << convertBinToDec(maxBDN);
        T--;
    }

    return 0;
}
