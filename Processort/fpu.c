#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elem{
	int val;
	struct elem * next;
};
typedef struct elem stack;

stack * stack_constructor(){
	stack * ret = malloc(sizeof(ret));
	ret->next = NULL;
	return ret;
}

void stack_push(stack * stk, int x){
	assert(stk);
	struct elem * new = malloc(sizeof(new));
	new->val = x;
	new->next = stk->next;
	stk->next = new;
}

int stack_pop(stack * stk){
	assert(stk);
	struct elem * kill = stk->next;
	assert(kill);
	stk->next = kill->next;
	
	int ret = kill->val;
	free(kill);
	
	return ret;
}

void stack_destructor(stack ** Sstk){
	assert(Sstk);
	struct elem * stk = *Sstk;
	assert(stk);
	
	struct elem * iterator = stk->next;
	while(iterator){
		struct elem * kill = iterator;
		iterator = iterator->next;
		free(kill);
	}
	free(stk);
	*Sstk = NULL;
}

void stack_dump(stack * stk){
	assert(stk);
	struct elem * iterator = stk->next;
	while(iterator){
		printf("%d ", iterator->val);
		iterator = iterator->next;
	}
	printf("\n");
}

int main(){
	stack * x = stack_constructor();
	
	char c=' ', dummy=' ';
	
	while(scanf("%c%c", &c, &dummy) == 2){
		if ('0' <= c && c <= '9') stack_push(x, c-'0');
		if (c == '+'){
			int a = stack_pop(x); int b = stack_pop(x);
			stack_push(x, a + b);
		}
		if (c == '-'){
			int a = stack_pop(x); int b = stack_pop(x);
			stack_push(x, b - a);
		}
		if (c == '*'){
			int a = stack_pop(x); int b = stack_pop(x);
			stack_push(x, a * b);
		}
		//stack_dump(x);
	}
	
	printf("%d\n", stack_pop(x));
	
	stack_destructor(&x);
	return 0;
}
