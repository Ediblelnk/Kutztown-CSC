#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int X; //global variable

void fatal_error(char code, int num) {
  switch(code) {
    case 'i': //INPUT ERROR
      printf("INPUT ERROR: EXPECTED 4 OR 5 INPUTS, GOT %d.\n", num-1);
      break;
    case 'f': //FORKING ERROR
      printf("FORKING ERROR: UNABLE TO CREATE CHILD PROCESS.\n");
      break;
    case 'p': //PROCESS REQUEST INPUT ERROR
      printf("INPUT ERROR: EXPECTED BETWEEN 1 AND 10 PROCESSES, GOT %d.\n", num);
      break;
    default:
      printf("UNKNOWN ERROR:\n");
  }

  exit(1);
}

void child(FILE* fp, int num_child, int* pX, int* pnum, int* pnump) {
  fprintf(fp, "BEFORE increment: Child number %d with PID of %d:\t x = %d, num = %d, nump = %d\n", num_child, getpid(), *pX, *pnum, *pnump);

  *pX = *pX + 50;
  (*pnum)++;
  (*pnump)++;
  
  fprintf(fp, "AFTER  increment: Child number %d with PID of %d:\t x = %d, num = %d, nump = %d\n", num_child, getpid(), *pX, *pnum, *pnump);

  exit(1);
}

void parent(FILE* fp, int num_child, pid_t p) {
  int status; 
  wait(&status);
  fprintf(fp, "Child Process %d with PID of %d has ended.\n", num_child, p);
}

void sequential_processes(FILE* fp, int num_fork, int* pX, int* pnum, int* pnump) {

  fprintf(fp, "CREATING %d SEQUENTIAL PROCESSES: X = %d, num = %d, nump = %d\n", num_fork, *pX, *pnum, *pnump);

  pid_t p;

  for(int i = 0; i < num_fork; i++) {
    p = fork();
    switch(p) {
      case -1:
        fatal_error('f', 0);
	break;
      case 0:
        child(fp, i+1, pX, pnum, pnump);
	break;
      default:
        parent(fp, i+1, p);
	break;
    }
  }
}

void concurrent_processes(FILE* fp, int num_fork, int* pX, int* pnum, int* pnump) {
  
  fprintf(fp, "CREATING %d CONCURRENT PROCESSES: X = %d, num = %d, nump = %d\n", num_fork, *pX, *pnum, *pnump);

  pid_t p;

  for(int i = 0; i < num_fork; i++) {
    p = fork();
    switch(p) {
      case -1:
        fatal_error('f', 0);
	break;
      case 0:
        child(fp, i+1, pX, pnum, pnump);
	break;
    }
  }

  for(int i = 0; i < num_fork; i++) {
    parent(fp, i+1, p);
  }
}

int main(int argc, char** argv) {
  //ensure proper number of arguments
  if(argc < 5 || 6 < argc) fatal_error('i', argc);
  
  //assign output to either file or to console
  FILE* fp = (argc == 6) ? fopen(argv[5], "a") : stdout;

  //assign variables from input
  int num_forks = atoi(argv[1]);
  X = atoi(argv[2]);
  int num = atoi(argv[3]);
  int* nump = (int*) malloc(sizeof(int));
  *nump = atoi(argv[4]);

  //ensure valid number of processes request
  if(num_forks < 1 || 10 < num_forks) fatal_error('p', num_forks);

  sequential_processes(fp, num_forks, &X, &num, nump);

  //assign variables from input again
  num_forks = atoi(argv[1]);
  X = atoi(argv[2]);
  num = atoi(argv[3]);
  *nump = atoi(argv[4]);

  concurrent_processes(fp, num_forks, &X, &num, nump);

  free(nump);
  fclose(fp);
  return 0;
}
