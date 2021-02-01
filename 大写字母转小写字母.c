#include <stdio.h>

int main(void){
	char ch;
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	  ch=ch+32;
	printf("%c",ch);
	
	return 0;
}
