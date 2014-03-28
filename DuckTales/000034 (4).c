#include <stdio.h>

union figna{
	char a[3];
	int b;
};

int main(){
	int flag1 = 1;
	FILE *fin = stdin;
	fin = fopen("source", "rb");

	FILE *fout = stdout;
	fout = fopen("cracked", "wb");
	
	union figna hren;
	hren.a[1] = fgetc(fin);
	hren.a[2] = fgetc(fin);
	
	do {
		hren.a[0] = hren.a[1];
		hren.a[1] = hren.a[2];
		hren.a[2] = fgetc (fin);
		
		if (hren.a[0] == 0xd9 && hren.a[1] == 0x45 && hren.a[2] == 0x08 && flag1){
			printf("OK\n");
			flag1 = 0;
			hren.a[0] = 0xd9;
			hren.a[1] = 0xeb;
			hren.a[2] = 0x90;
		}
		
		if (hren.a[0] == 0xd8 && hren.a[1] == 0xc1){
			printf("OK\n");
			hren.a[0] = 0xd8;
			hren.a[1] = 0xc1;
		}
		
		fputc(hren.a[0], fout);
    }while (!feof(fin));
	
	fputc(hren.a[1], fout);
	
	fclose(fin); fclose(fout);
	return 0;
}
