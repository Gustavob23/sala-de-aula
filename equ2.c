#include<stdio.h>
#include<math.h>

void calcRaiz( double a, double b, double c, double*x1, double*x2) {

    double delta;

    delta=b*b-4*a*c;

    *x1 = (-b + sqrt(delta))/(2 * a);
    *x2 = (-b - sqrt(delta))/(2 * a);
}

int main(){

    double k1, k2;

    calcRaiz(-1,8,3, &k1, &k2);

    printf("X1 = %lf, X2 = %lf\n\n", k1, k2);

return 0; 
}