/*
    * Question 2 implementation.
    This program cumputes the value of poisson distribution.
    * written by Tomer Shor & Adam Sin
    * Date: 10/5/2024
    * To run: $ make run    
    * default values set to (2,6)
*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <math.h>

#define ERROR -1

long double factorial(int n) ;
long double poisson(int k, int lambda);

int main(int argc, char *argv[]){
    if (argc != 3) {  //check for two arguments
        printf("Eror\n");
        return ERROR;
    }

    int lambda = atoi(argv[1]);
    int k = atoi(argv[2]);

    printf("The probability : P(X = %d) is: %Lf\n",k,  poisson(k, lambda));

    return 0;
}

long double poisson(int k, int lambda){
    return expl(-lambda)* powl(lambda, k) / factorial(k);;
}

long double factorial(int n) {
    long double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}