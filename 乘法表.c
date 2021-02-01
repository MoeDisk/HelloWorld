#include <stdio.h>

int main(){
	int i, j;
	for(i=0;i<=9;i++){
		for(j=0;j<=i;j++){
			printf("%d*%d=%d\t",j,i,j*i);
		}
		printf("\n");
	}
		return 0;
	}
