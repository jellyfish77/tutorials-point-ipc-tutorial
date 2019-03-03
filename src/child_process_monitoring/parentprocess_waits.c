#include <stdio.h> 			//printf()
#include <unistd.h>			//sleep()
#include <sys/types.h>
#include <sys/wait.h>		//wait()
#include <stdlib.h> 		//system(), atexit(), exit()

int main() {
	int pid;
	int status;
	pid = fork();

	// Child process
	if (pid == 0) {
		system("ps -ef");
		sleep(10);
		system("ps -ef");
		return 3; //exit status is 3 from child process
	} else {
		sleep(3);
		//the wait() system call waits for one of the children to terminate and returns its termination status in the buffer (&status)
		wait(&status);
		printf("In parent process: exit status from child is decimal %d, hexa %0x\n", status, status);
	}
	return 0;
}
