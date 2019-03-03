#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid;
	pid = fork();

	// Child process
	if (pid == 0) {
		system("ps -ef");
		sleep(10);
		system("ps -ef");
	} else {
		sleep(3);
	}
	return 0;
}
