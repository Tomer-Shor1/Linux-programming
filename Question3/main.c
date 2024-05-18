#include "stdio.h"

long double poisson(int k, int lambda);

int main(){
    printf("The poisson distribution : P(X = 1) with labmda = 2 is: %Lf\n", poisson(1,2));
    printf("The poisson distribution : P(X = 10) with labmda = 2 is:%Lf\n", poisson(10,2));
    printf("The poisson distribution : P(X = 2) with labmda = 2 is:%Lf\n", poisson(2,2));
    printf("The poisson distribution : P(X = 3) with labmda = 3 is:%Lf\n", poisson(3,3));
    printf("The poisson distribution : P(X = 3) with labmda = 100 is:%Lf\n", poisson(3,100));
    return 0;
}