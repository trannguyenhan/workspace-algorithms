/*
DBRACKET - Dãy ngoặc đúng phân biệt

Link Codeforces: https://codeforces.com/group/FLVn1Sc504/contest/274490/problem/D
Link Spoj      : https://vn.spoj.com/problems/DBRACKET/

Người ta định nghĩa một dãy ngoặc đúng như sau:

Xâu rỗng là một dãy ngoặc đúng.
Nếu A là dãy ngoặc đúng thì (A) cũng là một dãy ngoặc đúng
Nếu A, B là những dãy ngoặc đúng thì AB cũng là dãy ngoặc đúng.

Những dãy ngoặc sau được xem là đúng:
()(())
((()))

Những dãy ngoặc sau thì không:
)(
(((()))
)()()(

Một xâu S khác rỗng được gọi là xâu con của T nếu xâu S trùng với một dãy các kí tự liên tiếp của T.
Ví dụ "bcd" là xâu con của xâu "abcde" nhưng xâu "dc" thì không.

Cho một xâu T chỉ gồm các kí tự '(' và ')'  (kí tự mở ngoặc và đóng ngoặc).
Như vậy các xâu con của T có thể là một dãy ngoặc đúng hoặc không. Hãy đếm số lượng xâu con phân biệt của T mà là một dãy ngoặc đúng.

Input
Dòng đầu tiên chứa số n là số lượng bộ test (n<=20).
n dòng tiếp theo, mỗi dòng là một bộ test chứa xâu T. Biết rằng độ dài của xâu T không vượt quá 100.000 kí tự.

Output
Với mỗi bộ test, xuất ra số lượng xâu con phân biệt của T mà là một dãy ngoặc đúng.

Example
Input:
3
(()())()
(()()()()()
()()()(()())(()())

Output:
4
5
11

Giải thích: Với bộ test đầu, có 4 xâu con phân biệt là một dãy ngoặc đúng: "()" ; "()()"; "(()())"; "(()())
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

/*Ham kiem tra day ngoac dung hay sai, dung -> tra ve true, sai -> tra ve false*/
bool kiemTraNgoac(string str)
{
    vector<char> stackStr; // Su dung vector stackStr nhu 1 ngan xep
    for(int i=0; i<str.length(); i++)
    {
        // Khi ngan xep rong, neu str[i] la ')' -> khong phai ngoac dung -> ket thuc chuong trinh(false)
        // Neu str[i] = '(' -> nap phan tu vao ngan xep
        if(stackStr.empty())
        {
            if(str[i] == ')') return false;
            else
            {
                stackStr.push_back(str[i]);
            }
        } else // Neu ngan xep da co phan tu (khac rong)
        {
            // Neu str[i] = '(' -> Them vao ngan xep
            if(str[i] == '(')
            {
                stackStr.push_back(str[i]);
            } else // Neu str[i] = ')', Lay phan tu cuoi cung ra khoi ngan xep va xet tiep vong lap tiep theo
            {
                stackStr.pop_back();
            }
        }
    }

    if(stackStr.size() == 0) return true;
    else return false;
}


/*Substring - Lay ra day con tu phan tu thu i toi j cua str*/
string substring(string str, int i, int j)
{
    string tempstr;
    for(int k = i; k<=j; k++)
        tempstr.push_back(str[k]);
    return tempstr;
}

/*So sanh 1 chuoi voi 1 mang cua chuoi*/
// Neu chuoi so sanh khac tat ca phan tu trong mang -> true
// Nguoc lai, neu chi giong 1 phan tu -> false
bool kiemTraGiongNhau(vector<string> vt, string str)
{
    for(int i=0; i<vt.size(); i++)
        if(str.compare(vt[i]) == 0) return false;
    return true;
}

/*Dem so day ngoac dung con*/
// -> Qua thoi gian
int demNgoac(string str)
{
    vector<string> vt;
    int dem = 0;

    for(int i=0; i<str.length(); i++)
        for(int j=i+1; j<str.length(); j++)
        {
            string tempstr = substring(str,i,j);

            if(kiemTraNgoac(tempstr))
            {
                if(vt.size() == 0)
                {
                    vt.push_back(tempstr);
                    dem++;
                } else
                {
                    if(kiemTraGiongNhau(vt,tempstr))
                    {
                        vt.push_back(tempstr);
                        dem++;
                    }
                }
            }
        }
    return dem;
}

int main()
{
    int T;
    string str;
    cin >> T;

    while(T>0)
    {
        cin >> str;
        cout << demNgoac(str) << endl;
        T--;
    }
    return 0;
}

