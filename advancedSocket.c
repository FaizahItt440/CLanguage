#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BLOCKING 0
#define NONBLOCKING 1

int main(void)
{
	int sock,ret,on,mode;
	char buffer[100],oobdata;
	struct sockaddr_in saddr;
	char address[]={"192.168.1.1"};
	int serversock;
	struct protoent *pp;

	on= 1;
	ret = setsockopt(sock,SOL_SOCKET,SO_OOBINLINE,&on,sizeof(on));

	if (sockatmark(sock))
	{
		ret = read(sock,&oobdata,1);
	}
	else
	{
		ret = read(sock,buffer,sizeof(buffer));
	}

	sock = socket(AF_INET,SOCK_STREAM,0);

	mode = NONBLOCKING;

	ret = ioctl(sock,FIONBIO,&mode);

	saddr.sin_addr.s_addr = inet_addr(address);

	if(saddr.sin_addr.s_addr =  0xffffffff)
	{
		struct hostent *htpr=(struct hostent*)gethostbyname(address);

		if(hptr == NULL)
		{	println("Can't resolve the address");
		}
		else
		{
			struct in_addr **addrs;
 			addrs =(struct in_addr **)hptr->h_addr_list;
			memcpy(&saddr.sin_addr, *addrs,sizeof(struct in_addr));
		}

	pp = getprotobyname("tcp");
	if(pp)
	{
	serversock = socket(AF_INET,SOCK_STREAM,pp->p_proto);
	}

	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	saddr.sin_port = htons(MY_PORT);

	bind(serversock,(struct sockaddr *)&saddr, sizeof(saddr)); 

}
