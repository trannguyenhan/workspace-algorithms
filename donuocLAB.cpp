#include <iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

/* Khai bao bien toan cuc */
const int MAX = 1000;
int maxp[3]; // Khai bao luong nuoc lon nhat moi binh co the nhan duoc {o day la 3 binh}
int p[3]; // Luong nuoc tai moi binh

/*Ham do nuoc tu binh p[x] sang p[y]*/
void donuoc(int ix, int iy) // Do nuoc tu binh p[ix] vao binh p[iy]
{
    if(p[iy] == maxp[iy]) return; // Binh iy day thi khong do
    if(p[ix] == 0) return; // Binh ix rong thi cung khong co gi de do
    /*Sau moi lan do luon co 1 binh het hoac 1 binh tran*/
    if(p[ix]+p[iy] > maxp[iy]) // Do tran binh iy
    {
        p[ix] = p[ix] + p[iy] - maxp[iy];
        p[iy] = maxp[iy];
    } else // Do het binh ix
    {
        p[iy] = p[iy] + p[ix];
        p[ix] = 0;
    }
//   cout << p[1] << " " << p[2] << " " << p[3];
    return;
}

/*Luu tru qua trinh di chuyen cua tung binh*/
struct LUUTRUQD
{
    int move1;
    int move2;
    int move3;
};
struct LUUTRUQD print[MAX];
// print[x].move1 la luong nuoc tai binh 1 sau khi dich chuyen lan x
// print[x].move2 la luong nuoc tai binh 2 sau khi dich chuyen lan x
// print[x].move3 la luong nuoc tai binh 3 sau khi dich chuyen lan x

/*Danh dau vi tri da di qua*/
bool danhdau[MAX][MAX][MAX];

/*Printresult*/
void printresult(int c)
{
    for (int i=0; i<c; i++)
    {
        cout << print[i].move1 << " " << print[i].move2 << " " << print[i].move3;
        cout << endl;
    }
    cout << "-------" << endl;
    return;
}

/*dfs*/
int run = 0;
void explore(int ix, int iy, int iz)
{
    danhdau[p[ix]][p[iy]][p[iz]] = true;
    print[run].move1 = p[ix];   /*Luu tru trang thai cua binh moi*/
    print[run].move2 = p[iy];   /*khi do nuoc */
    print[run].move3 = p[iz];   /*(Luu tru trang thai sau khi thuc hien donuoc)*/
    if ((p[iy]==2) || (p[iz]==2)) // Neu gap trang thai can tim thi in ra man hinh
    {
        printresult(run+1);
    }
    run++;
    donuoc(ix,iy); if ((!danhdau[p[ix]][p[iy]][p[iz]]) && ((p[iy]!=2) || (p[iz]!=2)))
    {
        explore(ix,iy,iz);
    }
        p[ix] = print[run-1].move1; // Chuyen nuoc ve trang thai truoc do
        p[iy] = print[run-1].move2;
        p[iz] = print[run-1].move3;
    donuoc(ix,iz); if ((!danhdau[p[ix]][p[iy]][p[iz]]) && ((p[iy]!=2) || (p[iz]!=2)))
    {
        explore(ix,iy,iz);
    }
        p[ix] = print[run-1].move1;
        p[iy] = print[run-1].move2;
        p[iz] = print[run-1].move3;
    donuoc(iy,ix); if ((!danhdau[p[ix]][p[iy]][p[iz]]) && ((p[iy]!=2) || (p[iz]!=2)))
    {
        explore(ix,iy,iz);
    }
        p[ix] = print[run-1].move1;
        p[iy] = print[run-1].move2;
        p[iz] = print[run-1].move3;
    donuoc(iy,iz); if ((!danhdau[p[ix]][p[iy]][p[iz]]) && ((p[iy]!=2) || (p[iz]!=2)))
    {
        explore(ix,iy,iz);
    }
        p[ix] = print[run-1].move1;
        p[iy] = print[run-1].move2;
        p[iz] = print[run-1].move3;
    donuoc(iz,ix); if ((!danhdau[p[ix]][p[iy]][p[iz]]) && ((p[iy]!=2) || (p[iz]!=2)))
    {
        explore(ix,iy,iz);
    }
        p[ix] = print[run-1].move1;
        p[iy] = print[run-1].move2;
        p[iz] = print[run-1].move3;
    donuoc(iz,iy); if ((!danhdau[p[ix]][p[iy]][p[iz]]) && ((p[iy]!=2) || (p[iz]!=2)))
    {
        explore(ix,iy,iz);
    }
        p[ix] = print[run-1].move1;
        p[iy] = print[run-1].move2;
        p[iz] = print[run-1].move3;
    return;
}
int main()
{
    cout << "Nhap gia tri luong nuoc toi da trong cac binh" << endl;
    cout << "(Binh 2 va binh 3 luon day)" << endl;
    cout << "Nhap : ";
    cin >> maxp[1] >> maxp[2] >> maxp[3];
//    maxp[1] = 10; maxp[2] = 7; maxp[3] = 4;
    p[2] = maxp[2]; // Ban dau binh 2 day
    p[3] = maxp[3]; // Ban dau binh 3 day
    for (int i=0; i<MAX; i++)
        for (int j=0; j<MAX; j++)
            for (int k=0; k<MAX; k++)
                danhdau[i][j][k] = false;
    explore(1,2,3);
    return 0;
}
