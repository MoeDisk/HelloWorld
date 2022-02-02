#include<stdio.h>
#include<signal.h>
#include<unistd.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void waiting(),stop(),alarming();
int wait_mark;

int main()
{
	int p1,p2;
	if(p1=fork())             /*创建子进程p1*/
	{
		if(p2=fork())	    	/*创建子进程p2*/
		{
			wait_mark=1;
			signal(SIGINT,stop);    /*接收到^c信号，转stop*/
			signal(SIGALRM,alarming);/*接受SIGALRM
			waiting();
			kill(p1,16);            /*向p1发软中断信号16*/
			kill(p2,17);          /*向p2发软中断信号17*/
		
        	wait(0);              /*同步*/
			wait(0);
			printf("parent process is killed!\n");
			exit(0);
	    }
		else
	    {
			wait_mark=1;			
			signal(17,stop);
			signal(SIGINT,SIG_IGN);  /*忽略 ^c信号*/
			while (wait_mark!=0);
			lockf(1,1,0);
			printf("child process2  is killed by parent!\n");
			lockf(1,0,0);
			exit(0);
		}
	}
	else
	{
		wait_mark=1;
		signal(16,stop);
signal(SIGINT,SIG_IGN);  /*忽略^c信号*/
		while (wait_mark!=0)
		lockf(1,1,0);
		printf("child process1 is killed by parent!\n");
		lockf(1,0,0);
		exit(0);
	}
}

void waiting()
{
	sleep(5);
if (wait_mark!=0)
 kill(getpid(),SIGALRM);

}
void alarming()
{
	wait_mark=0;
}
void stop()
{
	wait_mark=0;
}
