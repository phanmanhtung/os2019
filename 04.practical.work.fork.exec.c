#include <stdio.h>
#include <unistd.h>
int main() {
	printf("Main before fork()\n");
	int pid = fork();
	if (pid == 0) {
		int pid2 = fork();
		if (pid2 == 0) {
			printf("I am the second child after fork(), launching free -h\n");
			char *args1[]= { "free", "-h" , NULL};
			execvp("free", args1);
			printf("Finished launching free -h\n");
		}
		else printf("I am parent after fork(), child is %d\n", pid2);

		printf("I am child after fork(), launching ps -ef\n");
		char *args[]= { "/bin/ps", "-ef" , NULL};
		execvp("/bin/ps", args);
		printf("Finished launching ps -ef\n");
	}
	else printf("I am parent after fork(), child is %d\n", pid);
	return 0;
}
