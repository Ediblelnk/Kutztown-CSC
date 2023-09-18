/* passiveTCP.c - passiveTCP */
/* Author: Douglas Comer and Richard Stevens             */
/* From Textbook: "Internetworking wtih TCP/IP:          */
/*           Client-Server Programming and Applications" */
/*           Publisher: Prentice Hall                    */

int	passivesock(const char *service, const char *transport,
		int qlen);

/*------------------------------------------------------------------------
 * passiveTCP - create a passive socket for use in a TCP server
 *------------------------------------------------------------------------
 */
int
passiveTCP(const char *service, int qlen)
/*
 * Arguments:
 *      service - service associated with the desired port
 *      qlen    - maximum server request queue length
 */
{
	return passivesock(service, "tcp", qlen);
}
