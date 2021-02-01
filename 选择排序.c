#include <stdio.h>

int main(){
	int a[5];
	for(int i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(a[i]<a[j]){
				int k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%5d",a[i]);
	}
}