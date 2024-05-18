// This file includes functions to be shared with main.c program.


#include "math.h"


long double factorial(int n);

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