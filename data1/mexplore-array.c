#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

void f() {
    // initializer list array syntax
    int arr[] = { 1, 2, 3, 4 };

    hexdump(arr, 16);

    //printf("--------\n");

    // other array syntax
    int arr2[5];

    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 128;
    arr2[3] = 17;
    arr2[4] = 0;

    hexdump(arr2, sizeof(arr2));

    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof((int*)arr));
}

int main() {
    f();
}
