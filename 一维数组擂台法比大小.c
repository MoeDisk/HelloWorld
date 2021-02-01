#include <stdio.h>

main(){
	int i,max,a[10];
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=1;i<10;i++){
		if(max<a[i])
		    max=a[i];
	}
	printf("max=%d",max);
}
