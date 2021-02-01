#include <stdio.h>

int main(){
	int m, i;
	scanf("%d",&m);
	for(i=2;i<=m/2;i++)
	     if(m%i==0)
	     break;
	     if(i>m/2&&m!=1)
	     printf("%d is a prime number!\n",m);
	     else
	     printf("No!\n");
	     
	     return 0;
}
