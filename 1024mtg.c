#include <stdio.h>

int main(){
	int lower, upper, m, g;
	scanf("%d%d",&lower,&upper);
	
	if(lower <= upper){
		printf("M G \n");
		for(m = lower; m <= upper; m++){
		g = m * 1024;
		printf("%d %d \n",m, g);
		}
	}else
	printf("Error");
	
	return 0;
}
