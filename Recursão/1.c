#include <stdio.h>

int imprimeNumero (int n){
    //if(n==1) return 1;
    if(n==0) return 1;
    imprimeNumero(n-1);
    printf("%d ", n);
}

int main(){
    int numero;

    scanf("%d", &numero);

    imprimeNumero(numero);

    printf("\n");

    return 0;
}
