#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include "cilindro.h"
#define pi 3.14159
 
typedef struct{
    double altura;
    double areaB;
}cilindro;
 /*
double area(cilindro c){
    double A, aux;
 
    aux = pow(c.raio, 2) * pi * c.raio;
    A = (2 * pi * c.raio * c.altura) + aux;
 
    return A;
}
*/
 
double volume(cilindro c){
    double V, aux;
    //aux = pow(c.raio, 2);
    V = c.altura * c.areaB;
 
    return V;
}
 
int main(){
    int qtd_test;
    cilindro ci;
    
    scanf("%d", &qtd_test);
    
    while(qtd_test!=0){
 
        scanf("%lf", &ci.altura);
        scanf("%lf", &ci.areaB);
     
       // double areaCilindro =  area(ci);
        double volumeCilindro = volume(ci);
     
        //printf("%.2lf", areaCilindro);
        printf("%.0lf %.0lf %.0lf\n",ci.altura, ci.areaB, volumeCilindro);
        //printf("%.2lf", volumeCilindro);
        qtd_test--;
    }
 
    return 0;
}