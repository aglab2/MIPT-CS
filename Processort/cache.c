#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 1100 

unsigned data[N][N];
unsigned dataP[N][N];

int gcd (int a, int b) {
	if (data[a-1][b-1]) return data[a-1][b-1];
	if (b==0) return a;
	return gcd(b, a%b);
}

int main(){
	memset(data, 0, sizeof(unsigned)*N*N);
	memset(dataP, 0, sizeof(unsigned)*N*N);
	
	int n = 0, d = 0;
	//unsigned long long t1 = clock();
	scanf("%d%d", &n, &d);
	 
	int i, j, k;
	
	for (i=0; i<=n; i++){
		for (j=0; j<=n; j++){
			data[i][j] = gcd(i+1, j+1);
			dataP[n-j][n-i] = data[i][j];
		}
	}
	
	unsigned long long int cur = 0;
	unsigned long long int res = 0;
	
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			cur = 0;
			for (k=0; k<n; k++) cur += data[i][k] * dataP[j][k];
			res += !(cur%d);
			//printf("%llu\n", cur);
		}
	}
	
	printf("%llu\n", res);
	//unsigned long long t2 = clock();
	//printf("%lg", ((double)(t2-t1))/CLOCKS_PER_SEC);
	return 0;
}
