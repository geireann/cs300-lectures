#include <stdio.h>
#include <stdlib.h>
#include "hexdump.h"

typedef struct {
} list_t;

void append(list_t* list, int value) {
}

int main() {
  list_t* l = (list_t*)malloc(sizeof(list_t));

  for (int i = 0; i < 100; i++) {
    append(l, i);
  }

  free(l);
}
