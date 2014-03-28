#include <string.h>
#include <stdlib.h>

char * whatisyourname(){
	char * ret = malloc(260);
	memset(ret, 0xff, 260);
	
	ret[256] = 0;
	ret[257] = 0;
	ret[258] = 0;
	ret[259] = 0;
	
	return ret;
}
/*
struct anomaly{
	char name_of_anomaly[256];
	int number_of_anomaly;
};

#include <stdio.h>

int main(){
	struct anomaly a;
	a.number_of_anomaly = 6;
	
	memcpy(a.name_of_anomaly, whatisyourname(), 260);
	printf("%d", a.number_of_anomaly);
	return 0;
}
*/
