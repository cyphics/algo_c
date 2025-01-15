#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void PrintBytes(void *ptr, int size) {
  unsigned char *p = ptr;
  for (int i = 0; i < size; i++) {
    printf("%02hhX ", p[i]);
  }
  printf("\n");
}

bool CompareArrays(void *ptr1, void *ptr2, int size) {
  return (memcmp(ptr1, ptr2, size) == 0);
}
