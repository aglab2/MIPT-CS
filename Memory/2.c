#include <stdio.h>
#include <string.h>

int main(){
	char wrd[4];
	short c = 0;
	
	while(scanf("%s", wrd) == 1){		
		if (!strcmp(wrd, "fe"))
			c = (c & 0b11111110) | 0b00000000;
		if (!strcmp(wrd, "ma"))
			c = (c & 0b11111110) | 0b00000001;
		if (!strcmp(wrd, "du"))
			c = (c & 0b11111101) | 0b00000000;
		if (!strcmp(wrd, "cl"))
			c = (c & 0b11111101) | 0b00000010;
		if (!strcmp(wrd, "nh"))
			c = (c & 0b11111011) | 0b00000000;
		if (!strcmp(wrd, "ha"))
			c = (c & 0b11111011) | 0b00000100;
		if (!strcmp(wrd, "sk"))
			c = (c & 0b11110111) | 0b00000000;
		if (!strcmp(wrd, "tr"))
			c = (c & 0b11110111) | 0b00001000;	
		if (!strcmp(wrd, "bn"))
			c = (c & 0b11001111) | 0b00000000;	
		if (!strcmp(wrd, "rd"))
			c = (c & 0b11001111) | 0b00010000;	
		if (!strcmp(wrd, "bw"))
			c = (c & 0b11001111) | 0b00100000;	
		if (!strcmp(wrd, "bk"))
			c = (c & 0b11001111) | 0b00110000;	
		if (!strcmp(wrd, "bu"))
			c = (c & 0b00111111) | 0b00000000;	
		if (!strcmp(wrd, "ge"))
			c = (c & 0b00111111) | 0b01000000;	
		if (!strcmp(wrd, "gy"))
			c = (c & 0b00111111) | 0b10000000;	
		if (!strcmp(wrd, "da"))
			c = (c & 0b00111111) | 0b11000000;	
	}
	
	printf("%x", c);
	
	return 0;
}
