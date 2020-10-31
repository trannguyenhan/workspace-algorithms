#include <iostream>

using namespace std;

/*Tinh gia tri f(x,y) bang de quy*/
int f(int x, int y )
{
    if ((x==0) && (y==0)) return 0;
    else
    {
        if ((x%3==0) && (y%2==0)) return f(x/3,y/2);
        else
        {
            if ((x%3==1) && (y%2==0)) return f((x-1)/3,y/2)+1;
            else
            {
                if ((x%3==2) && (y%2==0)) return f((x-2)/3,y/2);
                else
                {
                    if ((x%3==0) && (y%2==1)) return f(x/3,(y-1)/2)+1;
                    else
                    {
                        if ((x%3==1) && (y%2==1)) return f((x-1)/3,(y-1)/2)+2;
                        else
                        {
                            if ((x%3==2) && (y%2==1)) return f((x-2)/3,(y-1)/2)+1;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T>0)
    {
        int x, y;
        cin >> x >> y;
        cout << f(x,y);
        T--;
    }
    return 0;
}
