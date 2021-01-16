// ***** ductv
//       3/3/2017
//       Version 2 
//       Nhanh hon Version 1 khoang  6-7 lan tren random data 100000 dinh.
// ***** Code chua toi uu!  sua de chay trong O(n)?

#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#define MAX 100000


// Input: prufer code trong prufer[1][.]
//        voi n2 la n - 2 (n la so dinh cua cay)
// Muc tieu: xay dung prufer[0][.]
void pruferConstruction(int n2, int prufer[2][MAX])
{
  //int phantu[n2+2] = {0};      // so luong cua moi phan tu {0,...,n-1} xuat hien o dong duoi 

  int phantu[MAX] = {0};
  
  
  prufer[1][n2] = 0;           // Them phan tu thu n-2+1 la 0
  
  for (int i = 0; i < n2+1; i++) phantu[prufer[1][i]] ++;    //*** V2:  Khoi tao:
                                                              // So lan Moi phan tu xuat hien trong prufer code

  int min = 0;  while (phantu[min] > 0) min++;               // tim phan tu nho nhat xuat hien trong prufer code 

  for (int i = 0; i < n2+1; i++)                             // Tinh phan tu thu i cua dong thu 1
    {      
      prufer[0][i] = min;                                    // min duoc chon cho 
      phantu[min]++;                                         // va min khong dung duoc o buoc sau

      phantu[prufer[1][i]] --;                               // *** V2 :  giam so phan tu prufer[1][i] xuat hien trong prufer code vi
                                                             //           phan tu thu i khong duoc tinh   

                                                             // Tinh lai min
      if (phantu[prufer[1][i]] == 0 && min > prufer[1][i])
	min = prufer[1][i];
      else
	{
	  while (phantu[++min] > 0) ;                        // Van CAN TOI UU de duoc O(n)
	}
    }
  
}

// Ghi ra cay voi n dinh
// o dang  .dot de hien thi voi graphviz
void printDot(int n, int tree[2][MAX])
{
  cout<<"graph test {"<<endl;

  for (int i = 0; i < n-1; i++) 
    cout<<tree[0][i]<<" -- "<<tree[1][i]<<";"<<endl;
  
  cout<<"}";
  
}

void randomPruferCode (int n2, int prufer[2][MAX])
{
  srand (time(NULL));  
  for (int i = 0; i < n2; i++)
    {

      prufer[1][i] = rand() % (n2 + 2) ;

    }
  
}
int main(int argc, char *argv[])
{
  int n2 = MAX-2;                 //n-2 phan tu

  int prufer[2][MAX];//  = {
  //   {0},
  //   {2, 4, 0, 3, 3,1}         // prufer code o dong thu 2 
  // };

  randomPruferCode(n2, prufer);
  pruferConstruction(n2, prufer);
  //  printDot(n2+2, prufer);
  
  
  return 0;
}
