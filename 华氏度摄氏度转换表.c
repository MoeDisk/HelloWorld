#include <stdio.h>

int main(){
	int fahr, lower, upper;
	double celsius;
	printf("Enter lower \n");
	scanf("%d",&lower);
	printf("Enter upper \n");
	scanf("%d",&upper);
	
	if(lower <= upper){
		printf("Fahr celsius \n");
		for(fahr = lower; fahr <= upper; fahr++){
			celsius = (5.0/9.0)*(fahr-32);
			printf("%4d %6.1f \n",fahr, celsius);
		}
	}else
		printf("Invalid Value! \n");
		
		return 0;
}