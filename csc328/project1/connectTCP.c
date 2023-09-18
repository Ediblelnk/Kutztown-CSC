/*************************************************************
 *      
 * Filename: connectTCP.c 
 * From Comer, Stevens - Internetworking with TCP/IP, Vol 3, 
 *                          Linux / POSIX Sockets Version
 *                   Publisher: Prentice Hall
 * Page 84
 *
 * Purpose: Establish a TCP socket
 *
 *************************************************************/

int	connectsock(const char *host, const char *service,
		const char *transport);

/*------------------------------------------------------------------------
 * connectTCP - connect to a specified TCP service on a specified host
 *------------------------------------------------------------------------
 */
int
connectTCP(const char *host, const char *service )
/*
 * Arguments:
 *      host    - name of host to which connection is desired
 *      service - service associated with the desired port
 */
{
	return connectsock( host, service, "tcp");
}
