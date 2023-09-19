#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void* routine() {
  int x = 0;
  printf("In a thread: %d, %lu\n", getpid(), pthread_self());
  printf("Done in thread");
}

int main() {
  pthread_t t1, t2;

  if(pthread_create(&t1, NULL &routine, NULL) != 0) {
    //error stuff
    perror("pthread_create");
  }
  if(pthread_create(&t2, NULL &routine, NULL) != 0) {
    //error stuff
    perror("pthread_create");
  }

  if(pthread_join(t1, NULL) != 0) {
    //error stuff
    perror("pthread_join");
  }

  if(pthread_join(t2, NULL) != 0) {
    //error stuff
    perror("pthread_join");
  }

  return 0;
}
