#include <stdio.h> 
#include <stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#define MSGKEY 75          /*定义关键词MEGKEY*/
struct msgform                /*消息结构*/
{
	long mtype;
	char mtexe[100];         /*文本长度*/
}msg;
int msgqid,i;

void CLIENT( )
{
	int i;
	msgqid=msgget(MSGKEY,0777|IPC_CREAT);
	for(i=10;i>=1;i--)
	{
		 msg.mtype=i;
		 printf("(client)sent\n");
 		 msgsnd(msgqid,&msg,1030,0);       /*发送消息msg入msgid消息队列*/
	}
	exit(0);
}

void SERVER( )
{ 
  msgqid=msgget(MSGKEY,0777|IPC_CREAT); /*由关键字获得消息队列*/
  do
  {
	  msgrcv(msgqid,&msg,1030,0,0);  /*从队列msgid接受消息msg*/
	  printf("(server)receive\n");
  }while(msg.mtype!=1);             /*消息类型为1时，释放队列*/
   msgctl(msgqid, IPC_RMID,0);

}

int main()
{
  if(fork()) 
{
SERVER();
	  wait(0);
}
	else CLIENT( );
}
