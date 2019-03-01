#include<stdio.h>

/*
 * In the following program, an uninitialized static variable is added. This
 * means uninitialized segment (BSS) size would increase by 4 Bytes.
 * Note − In Linux operating system, the size of int is 4 bytes. Size of the
 * integer data type depends on the compiler and operating system support.
 */
int main() {
	static int mystaticint1;
	printf("Hello World\n");
	return 0;
}
