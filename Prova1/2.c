#include <stdio.h>
 
typedef struct{
    int a;
    int b;
    int c;
}triangulo;
 
int equilatero(triangulo L){
    if(L.a==L.b && L.a==L.c && L.b==L.c) return 1;
    else return 0;
}
 
int isoceles(triangulo L){
    if(L.a==L.b || L.a==L.c || L.b==L.c) return 1;
    else return 0;
}
 
float semiperimetro(triangulo L){
    float SP=0;
    SP = (L.a+L.b+L.c)/2;
 
    return SP;
}
 
int main(){
    triangulo T;
    int auxEQ=0, tempIS=0;
    float ResulSP;
    //int a, b, c;
 
    scanf("%d%d%d", &T.a, &T.b, &T.c);
 
 
    ResulSP = semiperimetro(T);
    auxEQ = equilatero(T);
    tempIS = isoceles(T);
 
    if(tempIS == 1) printf("SIM\n");
    else printf("NAO\n");
    //printf("%d", isoceles(T));
    if(auxEQ == 1) printf("SIM\n");
    else printf("NAO\n");
    //printf()
    printf("%.2f\n", ResulSP);
 
    return 0;
}