int x;

int main(){
	scanf("%d", &x);
	
	asm(
		"mov x, %eax\n"
	);
	return 0;
}
