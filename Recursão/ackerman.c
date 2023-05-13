#include <stdio.h>

unsigned long int ackerman(unsigned long int m, unsigned long int n){
    if(m==0) return n+1;
    if(m>0 && n==0) return ackerman(m-1, 1);
    if(m>0 && n>0) return ackerman(m-1, ackerman(m, n-1));
}

int main(){
    unsigned long int m, n;

    scanf("%lu %lu", &m, &n);

    printf("%lu\n", ackerman(m, n));

    return 0;
}
