/*************************************************************
 *      
 * Filename: errexit.c
 * From Comer, Stevens - Internetworking with TCP/IP, Vol 3, 
 *                          Linux / POSIX Sockets Version
 *                   Publisher: Prentice Hall
 * Page 87
 *
 * Purpose: Display error message and exit program
 *
 *************************************************************/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------
 * errexit - print an error message and exit
 *------------------------------------------------------------------------
 */
int
errexit(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(1);
}
