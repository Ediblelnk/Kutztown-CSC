/**
 * Filename:	project2.c
 * Author:	Schaefer, Peter
 * Assignment:	Fall 2023, Project 2: Multiprocessing
 * Course:	CSC 328 Network and Secure Programming
 * Professor:	Schwesinger
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>

int X; //global variable

/**
 * Description:	handles an error using a code and an accessory number
 * Parameters:	char	code:	code used to print the proper error message
 * 		int	num:	accessory number used to improve error message
 */
void fatal_error(char code, int num)
{
    switch (code)
    {
    case 'i': // INPUT ERROR
        printf("INPUT ERROR: EXPECTED 4 OR 5 INPUTS, GOT %d.\n", num - 1);
        break;
    case 'o': // FILE OPEN ERROR
        printf("FILE OPEN ERROR: UNABLE TO OPEN OR CREATE FILE.\n");
        break;
    case 'f': // FORKING ERROR
        printf("FORKING ERROR: UNABLE TO CREATE CHILD PROCESS.\n");
        break;
    case 'p': // PROCESS REQUEST INPUT ERROR
        printf("INPUT ERROR: EXPECTED BETWEEN 1 AND 10 PROCESSES, GOT %d.\n", num);
        break;
    case 'x': // FPRINTF ERROR
        printf("FPRINTF ERROR: UNABLE TO WRITE TO FILESTREAM.\n");
        break;
    default:
        printf("UNKNOWN ERROR:\n");
    }

  exit(1);
}

/**
 * Description: contains the actions that each child executes, then terminates the child.
 * 		each child processes does the following:
 * 			print the state of X, num, and nump.
 * 			each child will add 50 to global variable X, increment num and nump.
 * 			print the state of X, num, and nump.
 * Parameters:	FILE*	fp:		file or output that is wrote to
 * 		int	num_child:	number of the child
 * 		int*	pX:		pointer to global variable X
 * 		int*	pnum:		pointer to main variable num
 * 		int*	nump:		main variable nump
 */
void child(FILE *fp, int num_child, int *pX, int *pnum, int *nump)
{
    if (fprintf(fp, "BEFORE increment: Child number %d with PID of %d:\t  x = %d,\t  num = %d,\t  nump = %d\n", num_child, getpid(), *pX, *pnum, *nump) < 0)
        fatal_error('x', 0);

    // increment all the variables according to the specifications for the project.
    *pX = *pX + 50;
    (*pnum)++;
    (*nump)++;

    if (fprintf(fp, "AFTER  increment: Child number %d with PID of %d:\t  x = %d,\t  num = %d,\t  nump = %d\n", num_child, getpid(), *pX, *pnum, *nump) < 0)
        fatal_error('x', 0);

    exit(1);
}

/**
 * Description:	contains the actions that each parent executes. it waits for a child, then file prints when the child ends
 * Parameters:	FILE*	fp:		file or output that is wrote to
 * 		int	num_child:	number of the child
 * 		pid_t	p:		PID of the child process
 */
void parent(FILE *fp, int num_child, pid_t p)
{
    int status;
    wait(&status);
    if (fprintf(fp, "Child Process %d with PID of %d has ended.\n", num_child, p) < 0)
        fatal_error('x', 0);
}

/**
 * Description:	subroutine to sequentially create child processes and end the child processes.
 * Parameters:	FILE*	fp:		file or output that is wrote to
 * 		int	num_fork:	number of fork processes to create
 * 		int*	pX:		pointer to global variable X
 * 		int* 	pnum:		pointer to main variable num
 * 		int*	nump:		main variable nump
 */
void sequential_processes(FILE *fp, int num_fork, int *pX, int *pnum, int *nump)
{

    if (fprintf(fp, "\nCREATING %d SEQUENTIAL PROCESSES: X = %d, num = %d, nump = %d\n", num_fork, *pX, *pnum, *nump) < 0)
        fatal_error('x', 0);
    pid_t p;

    // fork, executes, and waits for the processes
    for (int i = 0; i < num_fork; i++)
    {
        p = fork();
        switch (p)
        {
        case -1:
            fatal_error('f', 0);
            break;
        case 0:
            child(fp, i + 1, pX, pnum, nump);
            break;
        default:
            parent(fp, i + 1, p);
            break;
        }
    }
}

/**
 * Description:	subroutine to concurrently create child processes and end the child processes.
 * Parameters:	FILE*	fp:		file or output that is wrote to
 * 		int	num_fork:	number of fork processes to create
 * 		int*	pX:		pointer to global variable X
 * 		int* 	pnum:		pointer to main variable num
 * 		int*	nump:		main variable nump
 */
void concurrent_processes(FILE *fp, int num_fork, int *pX, int *pnum, int *nump)
{

    if (fprintf(fp, "\nCREATING %d CONCURRENT PROCESSES: X = %d, num = %d, nump = %d\n", num_fork, *pX, *pnum, *nump) < 0)
        fatal_error('x', 0);
    pid_t p;

    // forks and executes the processes
    for (int i = 0; i < num_fork; i++)
    {
        p = fork();
        switch (p)
        {
        case -1:
            fatal_error('f', 0);
            break;
        case 0:
            child(fp, i + 1, pX, pnum, nump);
            break;
        }
    }

    // waits for each process to complete before continuing; avoids creating a orphan or zombie process.
    for (int i = 0; i < num_fork; i++)
    {
        parent(fp, i + 1, p);
    }
}

/**
 * Description:	main program. Takes between 4-5 commnad-line arguments.
 * 		Demonstrates how memory and variables work when a process is forked.
 * 		First, sequentially creates, executes, and terminates processes.
 * 		Then, concurrently create, executes, and termiantes processes.
 * Parameters:	int	argc:		number of arguments provided, includes executable as first arg.
 * 		char**	argc:		list of character strings, contains command-line arguments.
 */
int main(int argc, char **argv)
{
    // ensure proper number of arguments
    if (argc < 5 || 6 < argc)
        fatal_error('i', argc);

    // assign output to either file or to console
    FILE *fp = (argc == 6) ? fopen(argv[5], "a") : stdout;
    if (fp == NULL)
        fatal_error('o', 0);

    // assign variables from input
    int num_forks = atoi(argv[1]);
    X = atoi(argv[2]);
    int num = atoi(argv[3]);
    int *nump = (int *)malloc(sizeof(int));
    *nump = atoi(argv[4]);

    // ensure valid number of processes request
    if (num_forks < 1 || 10 < num_forks)
        fatal_error('p', num_forks);

    // run processes sequentially
    sequential_processes(fp, num_forks, &X, &num, nump);

    // assign variables from input again
    num_forks = atoi(argv[1]);
    X = atoi(argv[2]);
    num = atoi(argv[3]);
    *nump = atoi(argv[4]);

    // run processes concurrently
    concurrent_processes(fp, num_forks, &X, &num, nump);

    if (fprintf(fp, "\nALL SEQUENTIAL AND CONCURRENT PROCESSES HAVE BEEN CREATED, EXECUTED, AND DESTORYED.\n") < 0)
        fatal_error('x', 0);

    // frees allocated memory, closes filestream
    free(nump);
    fclose(fp);

  free(nump);
  fclose(fp);
  return 0;
}
