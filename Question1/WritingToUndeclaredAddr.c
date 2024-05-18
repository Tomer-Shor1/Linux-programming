/*
    This program will cause a segmentation fault because it tries to write to an undeclared address.
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

    int *p = NULL;
    *p = 23;
    return 0;
}
