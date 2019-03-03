#include <stdio.h>
#include <unistd.h>

void exitfunc() {
	printf("Called cleanup function - exitfunc()\n");
	return;
}

int main() {
	atexit(exitfunc);
	printf("Hello, World!\n");
<<<<<<< HEAD
	//call system call 'exit' to exit; this will exit without cleanup (atexit will not be called)
=======
	//system call to exit
>>>>>>> 5393974a142409806c07a5a73b36ccfc7f2ab508
	_exit (0);
}
