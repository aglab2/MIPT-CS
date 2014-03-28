#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *segmentNum;
int *segmentStr;
int *segmentEnd;
int N, X;

int checkIndex(int a){
	int i;
	for (i=0; i<N; i++){
		if (segmentNum[i] == a){
			return i;
		}
	}
	return -1;
}

int main(){
	int i;
	scanf("%d%d", &X, &N);
	
	segmentNum = malloc(N * sizeof(int));
	segmentStr = malloc(N * sizeof(int));
	segmentEnd = malloc(N * sizeof(int));
	
	for (i=0; i<N; i++)
		scanf("%d%x%x", segmentNum+i, segmentStr+i, segmentEnd+i);
	
	int bits = -1;
	X = (2 << 11) / X;
	
	while(X != 0) X >>= 1, bits++;
	
	printf("%d %d\n", bits, 2 << (bits-1));
	
	int cur;
	while(scanf("%x", &cur) == 1){
		int addr = cur;
		for (i=1; i <= bits; i++) addr &= ~(1 << (32-i));
		
		printf("%d:0x%x -> ", cur >> (32-bits), addr);
		
		int inx = checkIndex(cur >> (32-bits));
		
		if (inx == -1){
			printf("error\n");
		}else{
			if (segmentEnd[inx] <= addr){
				printf("error\n");
			}else{
				printf("0x%x\n", segmentStr[inx] + addr);
			}
		}
	}
	return 0;
}
