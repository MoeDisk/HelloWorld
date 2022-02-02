#include <stdio.h> 
#include <stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#define SHMKEY  75                   /*定义共享区关键词*/
int shmid,i;
int *addr;

int CLIENT()
{	
	int i;	
	shmid=shmget(SHMKEY,1024, 0777|IPC_CREAT);    /*获取共享区，长度1024，关键词SHMKEY*/
	addr=shmat(shmid,0,0);                /*共享区起始地址为addr*/	
	for(i=9;i>=0;i--) 	
	{		
		while(*addr!= -1);                  		
		printf("(client)sent\n");                 /*打印（client）sent*/		
		*addr=i;                             /*把i赋给addr*/	
	}	
	exit(0);
}

int SERVER()
{ 	
	do	
	{	while(*addr ==-1);	
		printf("(server)received\n%d",*addr);               /*服务进程使用共享区*/	
if(*addr!=0)
*addr=-1;	
	} while(*addr);	
    wait(0);
	shmctl(shmid,IPC_RMID,0);	
	}

 main()
{	
	shmid=shmget(SHMKEY,1024,0777|IPC_CREAT);  /*创建共享区*/	
	addr=shmat(shmid,0,0);                         /*共享区起始地址为addr*/	
*addr=-1;	
	if(fork())
	{
	 SERVER();	
	}
	else
	{ CLIENT();	
	} }
