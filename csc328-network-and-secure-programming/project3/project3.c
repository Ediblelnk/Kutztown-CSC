/**
 * Filename:	project3.c
 * Author:	Schaefer, Peter
 * Assignment: 	Fall 2023, Project 3: Threads
 * Course: 	CSC 328 Network and Secure Programming
 * Professor:	Schwesinger
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

int X; // global variable

// create a data wrapper to deliver to threads
typedef struct data
{
    int thread_num;
    int *num;
    int **nump;
} data_t;

/**
 * Description:	handles an error using a code and an accessory number
 * Parameters:	char	code:	code used to print the proper error message
 * 		int	info:	accessory number used to improve error message
 */
void fatal_error(char code, int info)
{
    switch (code)
    {
    case 'i': // INPUT ERROR
        printf("INPUT ERROR: EXPECTED 4 INPUTS, GOT %d.\n", info - 1);
        printf("USAGE TIP: ./project3 thread_num x_val num_val nump_val\n");
        break;
    case 't': // THREAD REQUEST ERROR
        printf("INPUT ERROR: EXPECTED BETWEEN 1 AND 10 THREADS, GOT %d.\n", info);
        break;
    case 'm': // MEMORY ALLOCATION ERROR
        printf("MEMORY ERROR: UNABLE TO ALLOCATE MEMORY.\n");
        break;
    default: // UNKNOWN ERROR
        printf("UNKNOWN ERROR: UNEXPECTED FATAL ERROR OCCURRED.\n");
    }

    exit(-1);
}

/**
 * Description:	contains the instructions that each thread must execute.
 * 		prints a before statement, increments values, and a after statement.
 * Parameters:	void*	arg:	wrapper struct containing thread_num and pointers to num and *nump
 */
void *routine(void *arg)
{
    // cast the argument wrapper
    data_t *data = (data_t *)arg;

    printf("BEFORE increment: Thread number %d with TID of %lu:  X = %d,  num = %d,  nump = %d\n", data->thread_num, pthread_self(), X, *data->num, **data->nump);

    // increment the variables
    X += 50;
    *data->num += 1;
    **data->nump += 1;

    printf("AFTER  increment: Thread number %d with TID of %lu:  X = %d,  num = %d,  nump = %d\n", data->thread_num, pthread_self(), X, *data->num, **data->nump);

    pthread_exit(NULL);
}

/**
 * Description:	subroutine to concurrently create threads, execute threads, and rejoin the threads.
 * Parameters:	int	nun_threads:	the number of threads that will be created, executed, and rejoined
 * 		int*	pnum:		a pointer to main variable num
 * 		int*	nump:		main variable nump
 */
void concurrent_processes(int num_threads, int *pnum, int *nump)
{
    printf("CREATING %d THREADS WITH:\n\tX = %d, num = %d, nump = %d\n\n", num_threads, X, *pnum, *nump);

    // declare and create threads
    pthread_t ts[num_threads];
    data_t wrapper[num_threads];
    for (int i = 0; i < num_threads; i++)
    {
        // create wrapper struct
        wrapper[i].thread_num = i + 1;
        wrapper[i].num = pnum;
        wrapper[i].nump = &nump;

        if (pthread_create(&ts[i], NULL, &routine, &wrapper[i]) != 0)
            perror("pthread_create");
    }

    // rejoin threads to main thread and continue
    for (int i = 0; i < num_threads; i++)
        if (pthread_join(ts[i], NULL) != 0)
            perror("pthread_join");

    printf("\nFINISHED %d THREADS. FINAL VARIABLE VALUES:\n\tX = %d, num = %d, nump = %d\n\n", num_threads, X, *pnum, *nump);
}

/**
 * Description:	main program. takes 4 command-line arguments.
 * 		demonstrates how memory and variables work when a process creates multiple threads.
 * 		concurrently create, executes, and rejoins threads.
 * Parameters:	int	argc:	number of arguments provided, includes executable as first arg.
 * 		char**	argv:	list of character strings, contains command-line arguments.
 */
int main(int argc, char **argv)
{
    // ensure proper number of arguments
    if (argc != 5)
        fatal_error('i', argc);

    // declare variables
    int num_threads, num;
    int *nump = (int *)malloc(sizeof(int));

    // ensure no error with memory allocation
    if (nump == NULL)
        fatal_error('m', 0);

    // assign variables from input
    num_threads = atoi(argv[1]);
    X = atoi(argv[2]);
    num = atoi(argv[3]);
    *nump = atoi(argv[4]);

    // ensure number of threads is in valid range
    if (num_threads < 1 || 10 < num_threads)
    {
        free(nump);
        fatal_error('t', num_threads);
    }

    // concurrent processes
    concurrent_processes(num_threads, &num, nump);

    free(nump);
    return 0;
}
