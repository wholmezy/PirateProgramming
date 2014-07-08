#include<cs50.h>
#include<stdio.h>


int main(void){
	int x = GetInt();
	printf("%i\n", x + 65 );
	printf("%c\n", (x % 26 ) + 65 );

}
