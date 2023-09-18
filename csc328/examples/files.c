#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  FILE *fp;

  fp = fopen("out.txt", "a");
  if (fp == NULL) {
    perror("fopen");
    exit(-1);
  }

  if (fprintf(fp, "Hello\n") < 0 ) {
    printf("Somehow, writing failed.");
    perror("fprintf");
  };
  fprintf(stdout, "%d, %s, %X\n", 10, "beansss", 10);
  
  fclose(fp);

  return 0; 
  
}
