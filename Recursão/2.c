#include <stdio.h>

unsigned int ackerman(long int m, long int n){
    if(m==0) return n+1;
    if(m>0 && n==0) return ackerman(m-1, 1);
    if(m>0 && n>0) return ackerman(m-1, ackerman(m, n-1));
}

int main(){
    unsigned long int m, n;

    scanf("%lu%lu", &m, &n);

    ackerman(m,n);
    printf("%lu", ackerman(m,n));

    return 0;
}