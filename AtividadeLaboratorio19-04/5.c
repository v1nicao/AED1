#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, qtd_casos, i;
    scanf("%d", &qtd_casos);
    if(qtd_casos <= 10 || qtd_casos >= 1){
        for(i=0; i<qtd_casos; i++){
            scanf("%d", &n);
            int resultado = fibonacci(n);
            printf("%d\n", resultado);
            resultado = 0;
        }
    }
    return 0;
}
