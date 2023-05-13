#include <stdio.h>

unsigned int duploFatorial(int n){
    if(n<=1) return 1;

    return n * duploFatorial(n-2);
}

int main(){
    unsigned int num;

    printf("Digite um numero para calcular o fatorial duplo:\n");
    scanf("%u", &num);

    duploFatorial(num);
    printf("%u\n", duploFatorial(num));

    return 0;
}