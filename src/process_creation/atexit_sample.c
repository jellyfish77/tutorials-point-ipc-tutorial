#include <stdio.h>
#include <stdlib.h>

void exitfunc() {
	printf("Called cleanup function - exitfunc()\n");
	return;
}

int main() {
	atexit(exitfunc);
	printf("Hello, World!\n");
<<<<<<< HEAD
	// call lib function 'exit' (will invoke atexit function for cleanup)
=======
	// lib function (will invoke atexit function for cleanup)
>>>>>>> 5393974a142409806c07a5a73b36ccfc7f2ab508
	exit (0);
}
