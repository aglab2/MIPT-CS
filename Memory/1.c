#include <stdio.h>

int main(){
	int a, i;
	scanf("%d", &a);
	
	int digits[3] = {(a / 100), (a / 10) % 10, a % 10};
	
	for (i=0; i<3; i++){
		if (digits[i] == 0) printf("---");
		if (digits[i] == 1) printf("--x");
		if (digits[i] == 2) printf("-w-");
		if (digits[i] == 3) printf("-wx");
		if (digits[i] == 4) printf("r--");
		if (digits[i] == 5) printf("r-x");
		if (digits[i] == 6) printf("rw-");
		if (digits[i] == 7) printf("rwx");		
	}
	
	return 0;
}
