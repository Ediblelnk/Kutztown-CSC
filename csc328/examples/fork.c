#include <stdio.h>
#include <unistd.h> // <-- required to use 'fork'
#include <stdlib.h>
#include <sys/wait.h>

int main() {

  pid_t pid;
  int status;

  pid = fork();

  if(pid < 0) {
    perror("fork");
    exit(-1);
  }

  //child
  if (pid == 0) {
    //child stuff
    printf("in child\n");

  } else { // pid is some nonzero value
    //parent stuff
    wait(&status);
    printf("in parnet\n");
  }

  return 0;
}
