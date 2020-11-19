#include<stdio.h>
#include<time.h>
#include<stdlib.h>


// Sinh so nguyen ngau nhien trong doan [min,max]
int randomInt(int Min, int Max){
    srand((int)time(0));
    return Min + rand() % (Max + 1 - Min);
}

// Sinh so thuc ngau nhien trong doan [min,max]
double randomDou(int Min, int Max){
    srand((int)time(0));
    double scale = (double) (rand() / (double)(RAND_MAX));
    return Min + scale*(Max - Min);
}

int main(){
    printf("%.2f",randomDou(0,5));
}
