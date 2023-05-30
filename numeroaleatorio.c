#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int qtd, max, min;
	int x, i;
	
	scanf("%d %d %d", &qtd, &min, &max);
	srand( time (0) );
	
	for(i = 0; i < qtd; i++){
	x = rand() % (max + 1 - min) + min;
	printf("x%d: %d\n", i, x);
	}
	
return 0;
}
	
