#include<stdio.h>
#include<math.h>
 
int main(){

int decimal=0;
int expoente=0;
int digito=1;
long int bin;
int x;	
	
	scanf("%ld", &bin);
	
	while(bin!=0){

	digito = bin % 10;
	decimal += digito * pow(2, expoente);
	expoente++;
	bin/=10;
	}	
	
	x = decimal;
	
	printf("%d", x);

return 0;
} 
