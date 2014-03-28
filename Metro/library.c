#include <stdio.h>
#include <dlfcn.h>

char a[10000];

int main(){
	scanf("%s", a);
	void * handle = dlopen(a, RTLD_LAZY);
	
	printf(handle ? "YES\n":"NO\n");
	return 0;
}
