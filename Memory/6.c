#include <stdio.h>

int main(){
float A10 = 10;

printf("%d\n", sizeof(A10));

printf("%1d%1d%1d%1d%1d%1d%1d%1d", 
        (A10 & 0x80) ? 1: 0,
        (A10 & 0x40) ? 1: 0,
        (A10 & 0x20) ? 1: 0,
        (A10 & 0x10) ? 1: 0,
        (A10 & 0x8) ? 1: 0,
        (A10 & 0x4) ? 1: 0,
        (A10 & 0x2) ? 1: 0,
        (A10 & 0x1) ? 1: 0);
	return 0;
}
