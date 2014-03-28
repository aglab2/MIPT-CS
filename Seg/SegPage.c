#include <stdio.h>
#include <stdlib.h>

int SegFind(int a, int * Seg_Num, int Seg_Ctr){
	int i;
	
	for (i=0; i<Seg_Ctr; i++)
		if (a == Seg_Num[i]) return i;
		
	return -1;
}

int PageFind(int a, int ** Page_Num, int * Page_Ctr, int SegNum){
	int i;
	
	for (i=0; i<Page_Ctr[SegNum]; i++)
		if (a == Page_Num[SegNum][i]) return i;
		
	return -1;
}

int main(){
	int i, j, X;
	
	int Seg_Max = 0, Page_Max = 0;
	int Seg_Ctr = 0;
	
	scanf("%d%d", &Seg_Max, &Page_Max);

	//segments
	scanf("%d", &Seg_Ctr);
	
	int	* Seg_Num = malloc(Seg_Ctr * sizeof(int));
	int * Seg_Len = malloc(Seg_Ctr * sizeof(int));

	for (i=0; i<Seg_Ctr; i++)
		scanf("%d%x", Seg_Num+i, Seg_Len+i);
	
	int * Page_Ctr = malloc(Seg_Ctr * sizeof(int));
	int ** Page_Num = malloc(Seg_Ctr * sizeof(int*));
	int ** Page_Mem = malloc(Seg_Ctr * sizeof(int*));
	
	for (i=0; i<Seg_Ctr; i++){
		scanf("%d", Page_Ctr+i);
		
		Page_Num[i] = malloc(Page_Ctr[i] * sizeof(int));
		Page_Mem[i] = malloc(Page_Ctr[i] * sizeof(int));
		
		for (j=0; j<Page_Ctr[i]; j++)
			scanf("%d%d", Page_Num[i]+j, Page_Mem[i]+j);
	}
	
	X = (1 << 12) / Seg_Max;
	int Seg_Bits = -1;
	while(X != 0) X >>= 1, Seg_Bits++;
	
	X = Seg_Max * 0x400 / Page_Max;
	int Page_Bits = -1;
	while(X != 0) X >>= 1, Page_Bits++;
	
	printf("%d %d %d\n", Seg_Bits, Page_Bits, 32-Seg_Bits-Page_Bits);
	
	int cur = 0; 
	while(scanf("%x", &cur) == 1){
		unsigned Current =  cur;
		int SegCur = Current >> (32-Seg_Bits);
		int PageCur = (Current << Seg_Bits) >> (32-Page_Bits);
		int SegOff = (Current << Seg_Bits) >> Seg_Bits;
		int PageOff = (Current << (Seg_Bits+Page_Bits)) >> (Seg_Bits + Page_Bits); 
		
		printf("%d:0x%x -> ", SegCur, SegOff);
		
		int SegCurInx = SegFind(SegCur, Seg_Num, Seg_Ctr);
		
		if (SegCurInx == -1){
			printf("segmentation fault\n");
			continue;
		}
		if (SegOff >= Seg_Len[SegCurInx]){
			printf("segmentation fault\n");
			continue;	
		}
		
		printf("%d:%d.0x%x -> ", SegCur, PageCur, PageOff);
		
		int PageCurInx = PageFind(PageCur, Page_Num, Page_Ctr, SegCurInx);
		
		if (PageCurInx == -1){
			printf("page fault\n");
			continue;
		}
		
		int Addr = Page_Mem[SegCurInx][PageCurInx] * Page_Max * 0x400;
		
		printf("0x%x+0x%x -> 0x%x\n", Addr, PageOff, Addr + PageOff);
	}
	return 0;
}
