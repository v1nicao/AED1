//este codigo faz uma calculadora simples, fazendo a potencia de x ao um certo numero, uma multiplicacao e uma divisao
#include <stdio.h>
#include <math.h>

void Menu(){
    printf("========>MENU<========\n");
    printf("1 - calcula x elevado a y\n");
    printf("2 - calcula a multiplicacao do primeiro pelo segundo\n");
    printf("3 - calcula a divisao do primeiro pelo segundo\n");
    printf("0 - saia do programa\n");
}

int main(){
    int option;
    float num1, num2, resultado;

    Menu();

    scanf("%d", &option);
    
    while(option != 0){
        switch (option) {
        case 1:
            scanf("%f%f", &num1, &num2);
            resultado = pow(num1,num2);

            printf("O resultado da potencia de %.0f elevado a %.0f e: %.0f\n", num1, num2, resultado);
            break;
        case 2:
            scanf("%f%f", &num1, &num2);
            resultado = num1*num2;
            printf("O resultado a multiplicacao de %.0f e %.0f: %.0f\n", num1, num2, resultado);
            break;
        case 3:
            scanf("%f%f", &num1, &num2);
            if(num2 == 0){
                printf("Erro!!! nao e possivel dividir por zero\n");
                break;
            } else{
                resultado = num1/num2;
                printf("O resultado da divisao entre %.0f e %.0f: %.2f\n", num1, num2, resultado);
            }
            break;
        }
        Menu();
        scanf("%d", &option);
    }

    return 0;
}