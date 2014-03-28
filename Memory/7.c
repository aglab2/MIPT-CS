#include <stdio.h>
#include <string.h>
#include <math.h>
#define BIGNUM 25000010

char data[BIGNUM];

char get(long a){
	return data[a/8] & (char)(1 << a%8);
}

void set(long a){
	data[a/8] &= (char)(255 - (1 << a%8));
}

void binPrint(char A10){
	printf("%1d%1d%1d%1d%1d%1d%1d%1d\n", 
        (A10 & 0x80) ? 1: 0,
        (A10 & 0x40) ? 1: 0,
        (A10 & 0x20) ? 1: 0,
        (A10 & 0x10) ? 1: 0,
        (A10 & 0x8) ? 1: 0,
        (A10 & 0x4) ? 1: 0,
        (A10 & 0x2) ? 1: 0,
        (A10 & 0x1) ? 1: 0);
}

int main(){
	long N = 0;
	scanf("%ld", &N);
	
	long sN = sqrt(N);
	
	memset(data, 0xff, BIGNUM);
	long i, j;
	for (i=2; i<=sN; i++)
		if (get(i) != 0)
			for (j=2*i; j<=N; j+=i)
				set(j);	
	
	long res = 0;
	for (i=2; i<=N; i++){
		if (get(i) != 0) res++;
	}
	
	printf("%ld", res);
	
	return 0;
}
