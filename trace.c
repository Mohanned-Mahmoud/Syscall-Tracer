#include "types.h"
#include "stat.h"
#include "trace.h"
#include "user.h"

void forkrun() {
	int fr = fork();
	if (fr == -1) {
		printf(1, "Fork error!\n");
		return;
	} else if (fr == 0) {
		close(open("README", 0));
		// exit the child early
		// Or output would be confusing
		exit();
	} else {
		wait();
	}
}

int main() {
	printf(1, "Process is being traced.\n");
	trace(T_TRACE);
	forkrun();

	trace(T_UNTRACE);
	printf(1, "Processs & forks being traced.\n");
	trace(T_TRACE | T_ONFORK);
	forkrun();

	trace(T_UNTRACE);
	printf(1, "Process not being traced.\n");
	forkrun();

	exit();
}
