#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	vi.pop_back();
	vector<int>::iterator it=vi.begin();
	for(int i=0;i<4;i++){
		printf("%d",(*it+i));
	}
	return 0;
}