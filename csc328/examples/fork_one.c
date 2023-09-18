#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t p;

  p = fork();


  switch(p) {
    case -1:
      // error stuff
      break;
    case 0:
      // child stuff
      printf("PID: %d,\t PPID: %d\n", getpid(), getppid());
      exit(1);
      break;
    default:
      // parent stuff
      printf("PID: %d,\t PPID: %d\n", getpid(), getppid());
      int status;
      printf("%d\n", status);
      wait(&status);
      printf("%d\n", status);
      break;
  }

/*
  if (p != 0) {
    
    int status;
    wait(&status);
    printf("%d\n", status);
  } else {
    return 4;
  }
*/
  return 0;
}
