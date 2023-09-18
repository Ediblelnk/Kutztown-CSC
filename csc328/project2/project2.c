#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

int X; // global variable

void fatal_error(char code, int num)
{
    switch (code)
    {
    case 'i': // INPUT ERROR
        printf("INPUT ERROR: EXPECTED 4 OR 5 INPUTS, GOT %d.\n", num - 1);
        break;
    }

    exit(1);
}

int main(int argc, char **argv)
{
    // ensure proper number of arguments
    if (argc < 5 || 6 < argc)
        fatal_error('i', argc);

    // assign output to either file or to console
    FILE *fp = (argc == 6) ? fopen(argv[5], "w") : stdout;

    // assign variables from input
    int num_forks = atoi(argv[1]);
    X = atoi(argv[2]);
    int num = atoi(argv[3]);
    int nump = atoi(argv[4]);

    printf("%d, %d, %d, %d", num_forks, X, num, nump);

    return 0;
}
