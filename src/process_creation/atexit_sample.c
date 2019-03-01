#include <stdio.h>
#include <stdlib.h>

void exitfunc() {
	printf("Called cleanup function - exitfunc()\n");
	return;
}

int main() {
	atexit(exitfunc);
	printf("Hello, World!\n");
	// call lib function 'exit' (will invoke atexit function for cleanup)
	exit (0);
}
