#include <stdio.h>

int main(){
	int mynumber = 10;
	int yournumber;
	scanf("%d",&yournumber);
	if(mynumber == yournumber)
         printf("Result True");
    if(yournumber < mynumber)
         printf("Sorry Smaller");
    else
         printf("Sorry Bigger");
         
    return 0;
}
