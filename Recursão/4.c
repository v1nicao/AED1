#include <stdio.h>
 
unsigned long int duploFatorial(long int n){
    if(n<=1) return 1;
 
    /*
    if(n%2 == 0) return n * duploFatorial(n-1);
    else return n*duploFatorial(n-2);
    */
    return n*duploFatorial(n-2);
}
 
int main(){
    unsigned long long int num;
 
    //printf("Digite um numero para calcular o fatorial duplo:\n");
    scanf("%llu", &num);
    
    if(num >= 1 && num <=100){
        if(num%2 == 0){
            num--;
            //duploFatorial(num);
        }
        duploFatorial(num);
        unsigned long long int resultado = duploFatorial(num);
        printf("%llu\n", resultado);

    }
 
    return 0;
}
