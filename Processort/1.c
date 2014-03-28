#include <stdio.h>

int main(){
	unsigned short command = 10;

	unsigned char r[4] = {0, 0, 0, 0};
	
	int p1 = 0;
	int p2 = 0;
	while(command){
		scanf("%hd", &command);
		
		switch(command){
			case 1:
				scanf("%d %d", &p1, &p2);
				r[p1-5] += r[p2-5];
				break;
			case 2:
				scanf("%d %d", &p1, &p2);
				r[p1-5] -= r[p2-5];
				break;
			case 3:
				scanf("%d %d", &p1, &p2);
				r[p1-5] = p2;
				break;
			case 4:
				printf("%hu %hu %hu %hu\n", r[0], r[1], r[2], r[3]);
				break;
		}
	}
	
	return 0;
}
