#include <stdio.h>

int main(){
	int T, tcase=1;
	scanf("%d",&T);
	while(T--){
		long long int a,b,c;
		scanf("%11d%11d%11d",&a,&b,&c);
		if(a+b>c){
			printf("Case #%d =True",tcase++);}
			else{
				printf("Case #d=False",tcase++);
			}
	}
	return 0;
}