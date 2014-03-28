#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i;
	
	scanf("%d", &N);
	
	unsigned int * pages = malloc(N * sizeof(int));
	for (i=0; i<N; i++) scanf("%x", pages+i);
	
	int curAdd = 0;
	scanf("%x", &curAdd);
	
	int curPage = (curAdd & 0xFC000000) >> 26;
	
	if (curPage >= N) {
		printf("error\n");
	}else{
		printf("%x\n", pages[curPage] + (curAdd & 0x03FFFFFF));
	}
	return 0;
}
