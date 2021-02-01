#include <stdio.h>
#include <queue>

using namespace std;

int main(){
	queue<int> q;
	for(int i=1;i<=5;i++){
		q.push(i);
	}
	printf("%d %d\n",q.front(),q.back());
	if(q.empty()==true){
		printf("Empty\n");
	}else{
		printf("Not Empty\n");
	}
	printf("%d\n",q.size());
	return 0;
}