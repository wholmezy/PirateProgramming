#include<stdio.h>
#include<cs50.h>

int main(void){
	printf("pick a number and i will make it a char!\n");
	int x = GetInt();

	printf("%i is %i!\n", x, (x %26));
}
