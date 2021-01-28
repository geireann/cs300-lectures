#include <stdio.h>

void f() {
    int local = 1;
    int* ptr = &local;

    printf("value of local: %d\n", local);

    printf("address of local: %p\n", &local);

    printf("value of ptr: %p\n", ptr);

    printf("value of *ptr: %d\n", *ptr);
}

int main(int argc, char* argv[]) {
  f();
}
