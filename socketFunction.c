#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PORT 2020
#define MAX_HOSTNAME 255
#define h_addr h_addr_list[0]

int select (int num,fd_set *readsds, fd_set *writesds, fd_set *exceptfds);
int getpeername (int sock,struct sockaddr *addr,socklen_t *len);
int getsockname(int sock,struct sockaddr *addr,socklen_t *len);
int getsockopt(int sock,int level,int optname,void *optval,socklen_t *optlen);
struct servent *getservbyport(int port,const char *proto);
int shutdown(int sock,int how);

struct hostent
{	char *h_name;
	char **h_aliases;
	int h_addrtype;
	int h_length;
	char **h_addr_list;
};

int main(void)
{
	fd_set read_set, exc_set;
	int sock,la_len,size;
	int ret;
	char hostbuffer[MAX_HOSTNAME+1];
	struct in_addr in;

	struct hostent *hp;

	FD_ZERO( &read_set);
	FD_SET(sock, &read_set);

	FD_ZERO(&exc_set);
	FD_SET(sock, &exc_set);

	sock = socket(AF_INET,SOCK_STREAM,0);
	ret = select(sock+1, &read_set, NULL, &exc_set, NULL);

	if (ret>0)
	{
		if (FD_ISSET(sock, &read_set))
		{
		 	read_set = read(;
		} 

		else if (FD_ISSET(sock,&exc_set))
		{
			 printf"Blank..";
		}
	}
	else
		printf "Error..";

	struct sockaddr_in servaddr;

	memset(&servaddr,0,sizeof(sock));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(25);
	servaddr.sin_addr.s_addr = inet_addr(INADDR_ANY);

	la_len = sizeof(servaddr);
	ret = getsockname(socket,(struct sockaddr_in *)&servaddr,&la_len);

	if (ret == 0)
	{
		printf("Local address is: %s\n",inet_ntoa(servaddr.sin_addr));
		printf("Local port is : %d\n",servaddr.sin_port);
	}

 	ret = getsockopt(sock,SOL_SOCKET,SO_SNDBUF,(void *)&size,
	(socklen_t *)&len);

	size = size * 2;

	ret = setsockopt(sock,SOL_SOCKET,SO_SNDBUF,(void *)&size,
	sizeof(size));

	ret = gethostname(hostbuffer, MAX_HOSTNAME);
	if (ret == 0)
	{
		printf("Host name is %s\n",hostbuffer);
	}

	inet_aton("192.168.1.1",&in);

	if (hp = gethostbyaddr(char *)&in.s_addr, sizeof(in.s_addr),
	AF_INET)
	{
		printf("Host name is %s\n",hp->h_name);
	}

	ret = getpeername(socket,(struct sockaddr_in *) &peeraddr, &la_len);

	if (ret == 0)
	{
		printf("Peer address is : %s\n", inet_ntoa(peeraddr.sin_addr));
		printf("Peer port is :%d\n",peeraddr.sin_port);
	}
	struct servent *sp;

	sp = getservbyport(htons(80),NULL);

	if (sp)
	{
		printf("Service %s is at port %d\n",sp->s_name,
		ntohs(sp->s_port));

	}


}
