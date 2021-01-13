#include<stdio.h>

void daonguoc(int n){
    if(n == 0) return;
    printf("%d", n%10);
    daonguoc(n / 10);
}

int main(){
    int n;
    scanf("%d", &n);
    daonguoc(n);
    return 0;
}
