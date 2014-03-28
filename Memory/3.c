#include <stdio.h>

int main(){
	short ip[4];
	short mk[4];
	short ad[4];
	char dummy;
	
	scanf("%hd%c %hd%c %hd%c %hd", ip, &dummy, ip+1, &dummy, ip+2, &dummy, ip+3);
	scanf("%hd%c %hd%c %hd%c %hd", mk, &dummy, mk+1, &dummy, mk+2, &dummy, mk+3);

	int i;
	for (i=0; i<4; i++) ad[i] = (ip[i] & mk[i]) | (255-mk[i]);

	printf("%hd.%hd.%hd.%hd", ad[0], ad[1], ad[2], ad[3]);

	return 0;
}
