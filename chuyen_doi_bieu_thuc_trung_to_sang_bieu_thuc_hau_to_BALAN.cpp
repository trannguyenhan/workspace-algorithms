#include <iostream>
#include<vector>
#include<string>
using namespace std;

// Kiem tra mot ki tu nhap vao co phai la toan hang hay khong!
// Toan hang bao gom : +(cong), -(tru), x(nhan), :(chia), () (dau ngoac)
bool CheckToanHang(char ch)
{
    if ((ch=='+') || (ch == '-') || (ch == '*') || (ch=='/') || (ch == '(') || (ch == ')'))
        return true;
    else return false;
}

// Gan thu tu uu tien cho cac phep toan
// Voi thu tu uu tien : nhan/chia > cong/tru
// => thu tu uu tien : nhan/chia = 2, cong/tru = 1
int SoTTUuTien(char ch)
{
    if ((ch == '*') || (ch == '/')) return 2;
    if ((ch == '+') || (ch == '-')) return 1;
    return 0;
}

// Dua ra bieu thuc hau to BALAN
void InBieuThucHauTo(string str)
{
    int lens = str.length();
    vector<char> vt; // vector se hoat dong nhu mot ngan xep voi cac thuoc tinh cua ngan xep nhu pop, push, size

    // Duyet bieu thuc tu dau toi cuoi
    for (int i=0; i<lens; i++)
    {
        // Neu khong phai toan hang -> dua ra man hinh
        if (!CheckToanHang(str[i])) cout << str[i];
        else
        {
            // Gap dau mo ngoac thi them vao ngan xep
                if (str[i]== '(')
                {
                    vt.push_back(str[i]);
                    continue;
                }

            // Gap dau dong ngoac, dua toan bo toan hang ra cho toi gap dau mo ngoac
                if (str[i] == ')')
                {
                    while(vt.back() != '(')
                    {
                        cout << vt.back();
                        vt.pop_back();
                    }
                    vt.pop_back(); // Lay not dau ngoac ra khoi ngan xep
                    continue;
                }

            // Neu ngan xep rong -> them toan hang vao ngan xep
            if ((vt.size() == 0) || (vt.back()=='('))
                vt.push_back(str[i]);
            // neu ngan xep khac rong, so sanh phan tu dang xet voi phan tu dau tien cua ngan xep
            else
            {
                // Neu toan toan hang dau ngan xep co thu tu uu tien >= str[i]
                // thi dua toan hang do ra, nap str[i] vao
                if (SoTTUuTien(vt.back()) >= SoTTUuTien(str[i]))
                {
                    cout << vt.back();
                    vt.pop_back();
                    vt.push_back(str[i]);
                } else // Khong thi nap toan hang vao ngan xep
                    vt.push_back(str[i]);
            }
        }
    }

    // Khi duyet het bieu thuc, dua het toan hang con lai ra khoi ngan xep
    while(vt.size() != 0)
    {
        cout << vt.back();
        vt.pop_back();
    }

    cout << endl; // Xuong dong, tiep tuc bo test tiep theo.
    return;
}
int main()
{
    vector<string> vt;
    int N; // N bieu thuc trung to can chuyen sang bieu thuc hau to BALAN
    cin >> N;

    for (int i=0; i<N; i++)
    {
        string temp;
        cin >> temp;
        vt.push_back(temp); // ta se co cac bo test lan luot la vt[0], vt[1], vt[2], vt[3],...
    }

    for (int i=0; i<N; i++)
    {
        InBieuThucHauTo(vt[i]);
    }
    return 0;
}
