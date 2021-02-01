#include <stdio.h>

#define N 10

int main(){
	int a[N];
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	
	int i,j,t;
	for(i=1;i<N;i++){
		t=a[i];
		for(j=i;j>0&&a[j-1]>t;j--)
		a[j]=a[j-1];
		if(j!=i) a[j]=t;
	}
	
	for(i=0;i<N;i++){
		printf("%5d",a[i]);
	}
}