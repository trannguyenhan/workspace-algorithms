#include <iostream>
 
using namespace std;
 
int N;
const int MAX = 10000;
int arr[MAX];
int tmp[MAX];
 
int x[MAX];
int res=0;

int findSplitPoint(int arr[], int n)
{
    int leftSum = 0 ;
 
    // traverse array element
    for (int i = 0; i < n; i++)
    {
        // add current element to left Sum
        leftSum += arr[i] ;
 
        // find sum of rest array elements (rightSum)
        int rightSum = 0 ;
        for (int j = i+1 ; j < n ; j++ )
            rightSum += arr[j] ;
 
        // split point index
        if (leftSum == rightSum)
            return i+1 ;
    }
 
    // if it is not possible to split array into
    // two parts
    return -1;
}
 
// Prints two parts after finding split point using
// findSplitPoint()
void printTwoParts(int arr[], int n)
{
    int splitPoint = findSplitPoint(arr, n);
 
    if (splitPoint == -1 || splitPoint == n )
    {
        return;
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
    	s+=arr[i];
        if(splitPoint-1 == i){
        	if(s>res){
        		res=s;
        		return;
			}
		}
        
    }
}
 
 
void in(int x[]){
	int sum1 = 0;
	int sum2 = 0;
    for (int i = 0; i < N; i++){
    	if(x[i]%2==1){
    		tmp[i]=arr[i];
		}
		else{
			tmp[i]=0;
		}
	}
//	cout<<endl;
//	for (int i = 0; i < N; i++){
//		cout<<x[i];
//	}
	printTwoParts(tmp, N);
}
 
void deQuy(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == N)
            in(x);
        else
            deQuy(i + 1);
        
    }
}
 
int main(){
    cin >> N;
	for(int i=0; i<N; i++){
    	cin >> arr[i];
	}
    deQuy(0);
    
    cout<<res;
}
