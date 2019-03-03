#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exitfunc() {
	printf("Called cleanup function - exitfunc()\n");
	return;
}

int main() {
	atexit(exitfunc);
	printf("Hello, World!\n");
	//call system call 'exit' to exit; this will exit without cleanup (atexit will not be called)
	_exit (0);
}
