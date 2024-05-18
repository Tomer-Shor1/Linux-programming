/*
    This program will cause a division by zero error.
*/


#include "stdio.h"


int main(){
    printf("%d", 2/0);  // this will cause a division by zero error
    return 0;
}