#include <iostream>

using namespace std;

/*Y tuong thuat toan duyet trau : Loai bo tung ki tu dau tien roi kiem tra doi xung cac ki tu con lai trong chuoi,
so ki tu bo di chinh la so ki tu can them vao de chuoi tro thanh chuoi guong*/
/*Han che : Van con chua dung toan bo test -> can cai tien de co thuat toan nhanh hon*/

bool checkDoiXung(string str)
{
    if(str.length() == 1) return true;
    else {
        int i = 0;
        int j = str.length() - 1;
        while(i<j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
}

int makePalindrome(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        string sub = str.substr(i);
        if(checkDoiXung(sub)) return i;
    }
}

int main()
{
    string str;
    cin >> str;
    cout << makePalindrome(str);
    return 0;
}
