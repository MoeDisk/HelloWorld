#include <stdio.h>

int main(){
	int den, flag, i, n;
	double item, sum;
	scanf("%d",&n);
	flag=1;
	den=1;
	sum=0;
	for(i=0;i<=n;i++){
		item=flag*1.0/den;
		sum=sum+item;
		flag=-flag;
		den=den+2;
	}
	printf("%f\n",sum);
	
	return 0;
}
