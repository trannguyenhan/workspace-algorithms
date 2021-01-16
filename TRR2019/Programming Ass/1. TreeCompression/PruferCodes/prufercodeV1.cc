// ***** ductv
//       3/3/2017
// ***** Code khong toi uu!  sua de chay trong O(n)?

#include <iostream>
using namespace std;

#define OK false
#define CAM true

#define MAX 100000


// Input: prufer code trong prufer[1][.]
//        voi n2 la n - 2 (n la so dinh cua cay)
// Muc tieu: xay dung prufer[0][.]
void pruferConstruction(int n2, int prufer[2][MAX])
{
  bool phantu[MAX] = {0};     // cac phan tu co the xuat hien o dong tren (OK) hoac khong (CAM)

  prufer[1][n2] = 0;           // Them phan tu thu n-2+1 la 0

  for (int i = 0; i < n2+1; i++) phantu[prufer[1][i]] = CAM;    // Khoi tao:
                                                                // Moi phan tu xuat hien trong prufer code bi cam

  for (int i = 0; i < n2+1; i++)                          // Tinh phan tu thu i cua dong thu 1
    {

      int min = 0;  while (phantu[min] == CAM) min++;     // tim phan tu nho nhat khong bi cam (KHONG TOI UU!!!)

      prufer[0][i] = min;                                 // phan tu nay chinh la dong 1
      phantu[min] = CAM;                                  // va phan tu nay khong co mat phia sau nua


      phantu[prufer[1][i]] = OK;                          // prufer[1][i] co the dung cho phan tu tiep theo

      for (int k = i+1; k < n2+1; k++ )                   // tru khi prufer[1][i] co mat o phia sau (CODE KHONG TOI UU !!!)
	if (prufer[1][i] == prufer[1][k])
	  {
	    phantu[prufer[1][i]] = CAM;
	    break;
	  }
    }

}

// Ghi ra cay voi n dinh
// o dang  .dot de hien thi voi graphviz
void printDot(int n, int tree[2][MAX])
{
  cout<<"graph test {"<<endl;

  for (int i = 0; i < n-1; i++)
    cout<<tree[0][i]<<" -- "<<tree[1][i]<<endl;

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
  //printDot(n2+2, prufer);

  

  return 0;
}
