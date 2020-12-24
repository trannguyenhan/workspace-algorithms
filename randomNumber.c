#include<stdio.h>
#include<time.h>
#include<stdlib.h>


// Sinh so nguyen ngau nhien trong doan [min,max]
int randomInt(int Min, int Max){
    //srand((int)time(0));
    return Min + rand() % (Max + 1 - Min);
}

// Sinh so thuc ngau nhien trong doan [min,max]
double randomDou(int Min, int Max){
    srand((int)time(0));
    double scale = (double) (rand() / (double)(RAND_MAX));
    return Min + scale*(Max - Min);
}

int main(){
    FILE *f;
    f = fopen("/media/trannguyenhan01092000/LEARN/dataset/random_number/number-random.txt", "w");

    for(int i=0; i<1000; i++){
        int run = randomInt(0,10000);
        printf("%d\n",run);
        fprintf(f, "%d\n", run);
    }

    fclose(f);
}
