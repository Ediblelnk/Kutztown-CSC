#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t p;

  for(int i = 0; i < 7; i++) {
    p = fork();
    switch(p) {
    case -1:
      // error stuff
      break;
      case 0:
        // child stuff
        printf("Process Num: %d,\tPID: %d,\t PPID: %d\n", i, getpid(), getppid());
        exit(1);
        break;
    }
  }

  for(int i = 0; i < 7; i++) {
    // parent stuff
    printf("PID: %d,\t PPID: %d\n", getpid(), getppid());
    int status; // create variable to get return from wait
    wait(&status);
    printf("%d\n", status);
  }
  return 0;
}
