//       ductv
//       /3/2017
//       Version 3 
//       Cai tien: min khong bao gio giam  
//       Complexity =  O(n)
//       Nhanh hon Version 2 khoang 100-200  lan tren random tree voi 100000 dinh

#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#define  MAX  1000


// Input: prufer code trong prufer[1][.]
//        voi n2 la n - 2 (n la so dinh cua cay)
// Muc tieu: xay dung prufer[0][.]
void pruferConstruction(int n2, int prufer[2][MAX])
{
  int phantu[n2+2] = {0};      // so luong cua moi phan tu {0,...,n-1} xuat hien o dong duoi 

  prufer[1][n2] = 0;           // Them phan tu thu n-2+1 la 0
  
  for (int i = 0; i < n2+1; i++) phantu[prufer[1][i]] ++;    //*** V3:  Khoi tao:
                                                              // So lan Moi phan tu xuat hien trong prufer code


  int min = 0;  while (phantu[min] > 0) min++;               // tim phan tu nho nhat xuat hien trong prufer code 
  int x = min;                                               // day la phan tu o dong tren
  
  for (int i = 0; i < n2+1; i++)                             // Tinh phan tu thu i cua dong tren
    {      
      prufer[0][i] = x;                                      // x duoc chon
      phantu[x]++;                                           // va x khong dung duoc o buoc sau nua

      
      phantu[prufer[1][i]] --;                               // *** V2 :  giam so phan tu prufer[1][i] xuat hien trong prufer code
                                                             //           vi phan tu prufer[1][i] co the lay neu khong xuat hien phia sau

      
                                                             // Tinh lai min va x
      if (phantu[prufer[1][i]] == 0 && min > prufer[1][i])
	{
	  x = prufer[1][i];	  
	}
      else{
	do min++; while (phantu[min] > 0) ;                  // *** V3: min luon tang ==> complexity =  O(n)
	x = min;
      }
    }
}


// Ghi ra cay voi n dinh
// o dang  .dot de hien thi voi graphviz
void printDot(int n, int tree[2][MAX])
{
  cout<<"graph tree {"<<endl;

  for (int i = 0; i < n-1; i++) 
    cout<<tree[0][i]<<" -- "<<tree[1][i]<<";"<<endl;
  
  cout<<"}"<<endl;
  
}

void randomPruferCode (int n2, int prufer[2][MAX])
{
  srand (time(NULL));  
  for (int i = 0; i < n2; i++)
    {
      prufer[1][i] = rand() % (n2 + 2) ;
    }
  prufer[1][n2] = 0;
}

void gentest (int n, int tree [2][MAX])
{
  int prufercode[MAX];
  
  randomPruferCode(n-2, tree);

  for (int i = 0; i < n-1; i++)
    {
      prufercode[i] = tree[1][i];
    }

  pruferConstruction(n-2, tree);

  //Dao thu tu ngau nhien
  
  srand (time(NULL));  
  int x = 0;
  int tmp0 = 0, tmp1 = 0;
  for (int i = 0; i < n-2; i++)
    {
      x = rand() % (n - 2 - i) + i;
      
      tmp0 = tree[0][i]; tmp1 = tree[1][i];
      
      tree[0][i] = tree[0][x +  1]; tree[1][i] = tree[1][x + 1];
      tree[0][x +  1] = tmp0;       tree[1][x+1] = tmp1;
    }
  
  cout <<"case= "<<endl;
  cout<<"input= ";
  cout<<n-1<<endl;
    for (int i = 0; i < n-1; i++) 
      cout<<tree[0][i]<<"  "<<tree[1][i]<<endl;

  
  
  cout<<"output= ";
  for (int i = 0; i < n-1; i++)
    {
      cout<<prufercode[i]<<" ";
    }
  cout<<endl;
  
}

int main(int argc, char *argv[])
{
  //int n2 = 6;                 //n-2 phan tu

  //  int prufer[2][MAX]  = {
  //  {0},
   //{5, 2, 4, 6, 7, 3, 1}      // dong 1
   //  {2, 4, 0, 3, 3, 1}         // prufer code o dong thu 2 
   //};

  int n = atoi(argv[1]);
  int n2 = n -2;
  int prufer[2][MAX];
  
 
  // randomPruferCode(n2, prufer);
  // pruferConstruction(n2, prufer);
  // printDot(n2+2, prufer);

  gentest(n, prufer);
  
  return 0;
}
