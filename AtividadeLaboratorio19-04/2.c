//esse programa vai indicar quando que o proximo cometa Halley vira
#include <stdio.h>

int main(){
    int A, lastAparence=1986, previsao, i;

    scanf("%d", &A);
    if(A >= 0 && A <= 10000){
        if(A > lastAparence){
            previsao = lastAparence;
            while(i != 110483) {
                previsao += 76;
                if(previsao > A){
                    printf("%d\n", previsao);
                    i = 110483;
                }
            }
        }
        else {
            previsao = lastAparence;
            while(i != 188469){
                previsao -= 76;
                if(A <= 76) {
                    printf("10\n");
                    i = 188469;
                }
                if(previsao < A){
                    printf("%d\n", previsao);
                    i = 188469;
                }
            }
        }

    } else {
        printf("Fora da margem estabelecida\n");
    }


    return 0;
}