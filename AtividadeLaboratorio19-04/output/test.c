#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n = 3;
    int resultado = fibonacci(n);
    printf("O %d-ésimo termo da sequência de Fibonacci é %d\n", n, resultado);
    return 0;
}
