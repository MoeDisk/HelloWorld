#include <stdio.h>

main(){
	int i,a[10];
	for(i=0;i<10;i++){
		a[i]=i;
	}
	for(i=0;i<10;i++){
		printf("a[%d]\n",i,a[i]);
	}
	printf("\n\n");
	for(i=9;i>=0;i--){
		printf("a[%d]\n",i,a[i]);
	}
}
