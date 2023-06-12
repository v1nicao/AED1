#include <stdio.h>

unsigned int convTOBin(unsigned int n){
    //if(n<0) return 0;
    if(n>0) {
        convTOBin(n/2);
        printf("%d", n % 2);
    }
}

int main(){
    unsigned int dec;

    scanf("%u", &dec);

    convTOBin(dec);
    printf("\n");

    return 0;
}