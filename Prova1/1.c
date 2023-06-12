#include <stdio.h>
 
double harmonica(double n){
    //int aux = 1;
    if(n==1) return 1;
 
    return 1/n+harmonica(n-1);
}
 
int main(){
    int qtd_n;
    double temp;
 
    scanf("%d", &qtd_n);
 
    temp = harmonica(qtd_n);
 
    printf("%.2lf", temp);
 
    return 0;
}