#include <stdio.h>
#include <string.h>

#define NUM1 100000000
#define NUM2 12500010

char data[NUM2];

int main(){
	int v, n, i, j, cur;
	memset(data, 0, NUM2);

	scanf("%d%d", &v, &n);
	
	for (i=0; i<v; i++){
		scanf("%d", &cur);
		
		data[cur/8] |= (1 << cur%8);
		for (j=2*cur; j<NUM1; cur++, j += cur)
			data[j/8] |= (1 << j%8);
	}
	
	int res = 0;
	
	for (i=0; i<n; i++){
		if (data[i/8] & (1 << i%8)){
			res++;
		}
	}
	
	printf("%d", res);
	
	return 0;
}
