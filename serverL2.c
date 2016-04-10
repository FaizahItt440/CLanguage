#include <stdio.h>
#include <stdib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define SMSIZE 100

int main(int argc,char *argv[])
{
	int shrmid;
	key_t key;
	char *shm;

	key = 9876;

	shrmid = shmget(key,SMSIZE,IPC_CREAT | 0666);
	if (shrmid < 0)
	{
		perror (*shmget*);
		exit(1);
	}

	shm = shmat(shrmid,NULL,0);

	if(shm == (char *) -1)
	{	
		perror(*shmat*);
		exit(1);
	}

	memcpy(shm,"Hello World",11);

	s = shm;
	s += 11;

	*s = 0;

	while(*shm != "*")
		sleep (1);

	
	return 0;
}
