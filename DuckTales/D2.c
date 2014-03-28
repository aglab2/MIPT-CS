#include <stdio.h>

unsigned char a[4];

int main(){
	int flag = 1;
	
	FILE *fin = stdin;
	//fin = fopen("source", "rb");

	FILE *fout = stdout;
	//fout = fopen("cracked", "wb");
	
	a[1] = fgetc (fin);
	a[2] = fgetc (fin); 
	a[3] = fgetc (fin);
	
	do {
		a[0] = a[1];
		a[1] = a[2];
		a[2] = a[3];
		a[3] = fgetc (fin);
		
		if (a[0] == 0xd9 && a[1] == 0x45 && a[2] == 0x08 && flag){
			//printf("OK - 1\n");
			flag = 0;
			a[0] = 0xd9;
			a[1] = 0xeb;
			a[2] = 0x90;
		}
		if (a[0] == 0xd8 && a[1] == 0xc1){
			//printf("OK - 2\n");
			a[0] = 0xde;
			a[1] = 0xc9;
		}
		
		fputc(a[0], fout);
    }while (!feof(fin));
	
	fputc(a[1], fout);
	fputc(a[2], fout);
	
	fclose(fin); fclose(fout);
	return 0;
}
