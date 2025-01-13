#include <stdio.h>

void PrintBytes(void *ptr, int size) {
	unsigned char *p = ptr;
	for (int i = 0; i<size; i++) {
		printf("%02hhX ", p[i]);
	}
	printf("\n");
}
