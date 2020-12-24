#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14;

typedef struct Diem{
    double x;
    double y;
    double z;
} Diem;

typedef struct DuongTron{
    char name;
    Diem Tam;
    double bankinh;
};

int main(){
    int soluong;
    vector<DuongTron> listDT;
    Diem dA, dB, dC;

    while(true){
        cout << "Ho va ten : Nguyen Quang Huy \n MSSV : 20183554 " << endl;
        cout << "** CHUONG TRINH QUAN LY CAC DUONG TRON **" << endl;
        cout << "** 1. Nhap duong tron va 3 diem bat ki **" << endl;
        cout << "** 2. In toa do tam, diem, ban kinh, vi tri, CHU VI, DIEN TICH, duong tron \n";
        cout << "va chu vi, toa do trong tam cua tam giac lap tu 3 diem **" << endl;
        cout << "** 0. Thoat **";
        cout <<"*******************************\n**   Nhap lua chon cua ban   **\n";

        int n;
        cin >> n;


        switch(n){
            case 0: return 0;
            case 1: {
                cout << "Ban da chon nhap danh sach hinh tron!" << endl;
                cout << "Nhap so luong duong tron : ";
                cin >> soluong;
                for(int i=0; i<soluong; i++){
                    DuongTron tmp;
                    char tmp1;
                    cout << "Nhap ten duong tron thu " << i+1 << " : ";
                    cin >> tmp1; tmp.name = tmp1; // nhap ten

                    double tmp0;
                    cout << "Nhap ban kinh : ";
                    cin >> tmp0; tmp.bankinh = tmp0;

                    double tmp2;
                    cout << "x : ";
                    cin >> tmp2;

                    int tmp3;
                    cout << "y : ";
                    cin >> tmp3;

                    int tmp4;
                    cout << "z : ";
                    cin >> tmp4;

                    Diem tmp5;
                    tmp5.x = tmp2;
                    tmp5.y = tmp3;
                    tmp5.z = tmp4;

                    listDT.push_back(tmp);
                }

                cout << "Nhap diem A" << endl;
                cout << "x : "; cin >> dA.x;
                cout << "y : "; cin >> dA.y;
                cout << "z : "; cin >> dA.z;

                cout << "Nhap diem B:" << endl;
                cout << "x : "; cin >> dB.x;
                cout << "y : "; cin >> dB.y;
                cout << "z : "; cin >> dB.z;

                cout << "Nhap diem C:" << endl;
                cout << "x : "; cin >> dC.x;
                cout << "y : "; cin >> dC.y;
                cout << "z : "; cin >> dC.z;

                break;
            }

            case 2: {
                if(listDT.size() == 0){
                    cout << "Ban chua nhap du lieu duong tron va 3 diem A, B, C! moi nhap lai";
                    break;
                }

                for(DuongTron dt : listDT){
                    cout << "Duong tron " << dt.name << endl;

                    cout << "Chu vi duong tron la : " << PI * dt.bankinh << endl;

                    cout << "Toa do trung diem tu tam toi diem A : " << (dt.Tam.x + dA.x)/2 << " ";
                    cout << (dt.Tam.y + dA.y)/2 << " " << (dt.Tam.z + dA.z)/2 << endl;

                    cout << "Toa do trung diem tu tam toi diem B : " << (dt.Tam.x + dB.x)/2 << " ";
                    cout << (dt.Tam.y + dB.y)/2 << " " << (dt.Tam.z + dB.z)/2 << endl;

                    cout << "Toa do trung diem tu tam toi diem C : " << (dt.Tam.x + dC.x)/2 << " ";
                    cout << (dt.Tam.y + dC.y)/2 << " " << (dt.Tam.z + dC.z)/2 << endl;

                    double DT_A = sqrt((dt.Tam.y - dA.y)*(dt.Tam.y - dA.y) + (dt.Tam.x - dA.x)*(dt.Tam.x - dA.x) + (dt.Tam.z - dA.z)*(dt.Tam.z - dA.z));
                    double DT_B = sqrt((dt.Tam.y - dB.y)*(dt.Tam.y - dB.y) + (dt.Tam.x - dB.x)*(dt.Tam.x - dB.x) + (dt.Tam.z - dB.z)*(dt.Tam.z - dB.z));
                    double DT_C = sqrt((dt.Tam.y - dC.y)*(dt.Tam.y - dC.y) + (dt.Tam.x - dC.x)*(dt.Tam.x - dC.x) + (dt.Tam.z - dC.z)*(dt.Tam.z - dC.z));

                    if(DT_A < dt.bankinh){
                        cout << "Diem A nam trong duong tron" << endl;
                    } else {
                        if(DT_A == dt.bankinh){
                            cout << "Diem A nam tren duong tron" << endl;
                        } else {
                            cout << "Diem A nam ngoai duong tron" << endl;
                        }
                    }

                    if(DT_B < dt.bankinh){
                        cout << "Diem B nam trong duong tron" << endl;
                    } else {
                        if(DT_A == dt.bankinh){
                            cout << "Diem B nam tren duong tron" << endl;
                        } else {
                            cout << "Diem B nam ngoai duong tron" << endl;
                        }
                    }

                    if(DT_C < dt.bankinh){
                        cout << "Diem C nam trong duong tron" << endl;
                    } else {
                        if(DT_A == dt.bankinh){
                            cout << "Diem C nam tren duong tron" << endl;
                        } else {
                            cout << "Diem C nam ngoai duong tron" << endl;
                        }
                    }

                    cout << "Toa do trong tam G cua tam giac ABC la : ";
                    cout << (dA.x + dB.x + dC.x)/3 << " " << (dA.y + dB.y+ dC.y)/3 << " " << (dA.z + dB.z + dC.z)/3 << endl;

                    cout << "Do dai doan thang IG";
                    double i_x = dt.Tam.x;
                    double i_y = dt.Tam.y;
                    double i_z = dt.Tam.z;

                    double g_x = (dA.x + dB.x + dC.x)/3;
                    double g_y = (dA.y + dB.y + dC.y)/3;
                    double g_z = (dA.z + dB.z + dC.z)/3;

                    cout << sqrt((i_x - g_x)*(i_x - g_x) + (i_y - g_y)*(i_y - g_y) + (i_z - g_z)*(i_z - g_z));

                }
                break;
            }

            default:{
                cout << "Lua chon ban nhap khong dung! moi ban nhap lai!";
                break;
            }
        }
    }

    return 0;
}
