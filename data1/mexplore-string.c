#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

char global_st[] = "Hello CS131!";

void f() {
    char local_st[] = "We <3 systems";

    hexdump(global_st, 12);
    hexdump(local_st, 13);

    //char* allocated_st = (char*)malloc(1);
    //sprintf(allocated_st, "C programming is cool");

    //hexdump(allocated_st, strlen(allocated_st));
}

int main() {
    f();
}
