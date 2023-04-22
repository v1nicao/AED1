#include <stdio.h>

int main(){
    char operacao;
    int i, j, k, lin, col;

    scanf("%d %d", &lin, &col);
    if(lin > 10 || col > 10){
        printf("ERROR\n");
    } else if(lin<1 || col < 1){
        printf("ERROR\n");
    }
    int mat1[lin][col];
    int mat2[lin][col];
    int matriz[lin][col];

    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    getchar();
    scanf(" %c", &operacao);
    
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

    switch(operacao){
        case '+':
        for(i=0; i<lin; i++){
            for(j=0; j<col; j++){
                matriz[i][j] = mat1[i][j]+mat2[i][j];
            }
        }
        for(i=0; i<lin; i++){
            for(j=0; j<col; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
        break;
        case 'x':
        for(i=0; i<lin; i++){
            for(j=0; j<col; j++){
                matriz[i][j] = 0;
                for(k=0; k<col; k++){
                    matriz[i][j] += mat1[i][k]*mat2[k][j];
                }
            }
        }
        for(i=0; i<lin; i++){
            for(j=0; j<col; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
        break;
        default:
        printf("ERROR\n");
    }

    return 0;
}
