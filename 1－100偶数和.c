#include <stdio.h>

int main(){
	int a, b = 0;
	for(a = 1; a <= 100; a++)
	if(a % 2 == 0)
	b = b + a;
	printf("%d",b);
	
	return 0;
}
