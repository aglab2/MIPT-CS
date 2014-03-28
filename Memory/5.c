#include <stdio.h>
#include <float.h>

int main(){
	char c;
	scanf("%c", &c);
	
	if (c == 'f') printf("%d", FLT_MANT_DIG-1);
	if (c == 'd') printf("%d", DBL_MANT_DIG-1);
	if (c == 'l') printf("%d", LDBL_MANT_DIG-1);
	
	return 0;
}
