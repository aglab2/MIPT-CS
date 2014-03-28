#include <stdio.h>
#include <string.h>
#define N 1024

char str[N];

int main(){
	char flag[4]={0,0,0,0};
	while(scanf("%s", str) == 1){
			if (!strcmp(str, "%eax") ||
				!strcmp(str, "%ebx") ||
				!strcmp(str, "%ecx") ||
				!strcmp(str, "%edx") ||
				!strcmp(str, "%esp") ||
				!strcmp(str, "%ebp") ||
				!strcmp(str, "%ecs") ||
			    !strcmp(str, "%eds")) flag[0] = 1, flag[2] = 1;
		
			if (!strcmp(str, "%rax") ||
				!strcmp(str, "%rbx") ||
				!strcmp(str, "%rcx") ||
				!strcmp(str, "%rdx") ||
				!strcmp(str, "%rsp") ||
				!strcmp(str, "%rbp") ||
				!strcmp(str, "%rcs") ||
			    !strcmp(str, "%rds")) flag[0] = 1, flag[2] = 1, flag[3] = 1;   
			    
			if (!strcmp(str, "eax") ||
				!strcmp(str, "ebx") ||
				!strcmp(str, "ecx") ||
				!strcmp(str, "edx") ||
				!strcmp(str, "esp") ||
				!strcmp(str, "ebp") ||
				!strcmp(str, "ecs") ||
			    !strcmp(str, "eds")) flag[2] = 1;
		
			if (!strcmp(str, "rax") ||
				!strcmp(str, "rbx") ||
				!strcmp(str, "rcx") ||
				!strcmp(str, "rdx") ||
				!strcmp(str, "rsp") ||
				!strcmp(str, "rbp") ||
				!strcmp(str, "rcs") ||
			    !strcmp(str, "rds")) flag[2] = 1, flag[3] = 1;   
	
			if (!strcmp(str, "finit")) flag[1] = 1;
			if (!strcmp(str, "fld")) flag[1] = 1;
			if (!strcmp(str, "fst")) flag[1] = 1;
		}
		
	printf("%d %d %d %d", flag[0], flag[1], flag[2], flag[3]);
	return 0;
}
