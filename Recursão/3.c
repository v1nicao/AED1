#include <stdio.h>

int numeroReverso(int n, int l, int k) {
    if (n == 0) {
        return 0;
    }
    if (n % 10 == 0) {
        return numeroReverso(n / 10, l, k);
    }
    if (l == -1) {
        l = k;
    }
    return (n % 10) * potencia(10, l) + numeroReverso(n / 10, l - 1, k);
}

int potencia(int b, int e) {
    if (e == 0) {
        return 1;
    }
    return b * potencia(b, e - 1);
}

int numeroDigitos(int n) {
    if (n == 0) {
        return 1;
    }
    return 1 + numeroDigitos(n / 10);
}

int main() {
    int n, r;
    printf("Digite um numero:\n");
    scanf("%d", &n);
    r = numeroReverso(n, -1, numeroDigitos(n) - 1);
    printf("O numero reverso de %d eh %d\n", n, r);
    printf("O valor de %d^r eh %d\n", n, potencia(n, r));
    return 0;
}