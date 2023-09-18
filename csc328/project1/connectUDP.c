/*************************************************************
 *      
 * Filename: connectUDP.c 
 * From Comer, Stevens - Internetworking with TCP/IP, Vol 3, 
 *                          Linux / POSIX Sockets Version
 *                   Publisher: Prentice Hall
 * Page 84
 *
 * Purpose: Establish a connected UDP socket
 *
 *************************************************************/


int	connectsock(const char *host, const char *service,
		const char *transport);

/*------------------------------------------------------------------------
 * connectUDP - connect to a specified UDP service on a specified host
 *------------------------------------------------------------------------
 */
int
connectUDP(const char *host, const char *service )
/*
 * Arguments:
 *      host    - name of host to which connection is desired
 *      service - service associated with the desired port
 */
{
	return connectsock(host, service, "udp");
}
