#include <stdio.h>
#include <string.h>
#include <math.h>

#define BIGNUM 25000010

char data[BIGNUM];

char get(long a){
	return data[a/8] & (char)(1 << a%8);
}

void set0(long a){
	data[a/8] &= ~(char)(1 << a%8);
}

void toggle(long a){
	data[a/8] ^= (char)(1 << a%8);
}

int main(){
	long limit;
	scanf("%ld", &limit);
	
	if (limit == 2){
		printf("1\n"); return 0;
	}
	if (limit == 3 && limit == 4){
		printf("2\n"); return 0;
	}
	if (limit == 5){
		printf("3\n"); return 0;
	}
		
	long sqr_lim;
	long x2, y2;
	long i, j;
	long n;
 
	sqr_lim = (long)sqrt((long double)limit);
	memset(data, 0, BIGNUM);
	toggle(2);
	toggle(3);
 
	x2 = 0;
	for (i = 1; i <= sqr_lim; i++) {
		x2 += 2 * i - 1;
		y2 = 0;
		for (j = 1; j <= sqr_lim; j++) {
			y2 += 2 * j - 1;
 
			n = 4 * x2 + y2;
			if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
				toggle(n);
 
			// n = 3 * x2 + y2; 
			n -= x2; // Оптимизация
			if ((n <= limit) && (n % 12 == 7))
				toggle(n);
 
			// n = 3 * x2 - y2;
			n -= 2 * y2; // Оптимизация
			if ((i > j) && (n <= limit) && (n % 12 == 11))
				toggle(n);
		}
	}
 
	// Отсеиваем кратные квадратам простых чисел в интервале [5, sqrt(limit)].
	// (основной этап не может их отсеять)
	for (i = 5; i <= sqr_lim; i++) {
		if (get(i)) {
			n = i * i;
			for (j = n; j <= limit; j += n) {
				set0(j);
			}
		}	
	}
 
	long res = 3;
	for (i = 6; i <= limit; i++) {  // добавлена проверка делимости на 3 и 5. В оригинальной версии алгоритма потребности в ней нет.
		if ((get(i)) && (i % 3 != 0) && (i % 5 !=  0)){
			res++;
		}
	}
	
	printf("%ld", res);

return 0;
}
