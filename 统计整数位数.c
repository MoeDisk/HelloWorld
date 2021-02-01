#include <stdio.h>

int main(void){
	int count=0, num;
	scanf("%d",&num);
	do{
		num=num/10;
		count++;
	}
	while(num!=0);
	printf("%d",count);
	
	return 0;
}
