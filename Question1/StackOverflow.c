/*
    This program will cause a stack overflow because the recursive function is calling itself infinitely.
*/


void recursiveFunction() {
    recursiveFunction(); // This will cause a stack overflow
}

int main() {
    recursiveFunction();
    return 0;
}
