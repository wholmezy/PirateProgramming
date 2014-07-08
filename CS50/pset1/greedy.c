#include<stdio.h>
#include<cs50.h>
#include<math.h>


int main(void){
	int t = 0; //Number of coins given
	printf("Yo! How much money you want?\n");
	float change = GetFloat(); 
	change = change * 100; //amount of change the user wants.
	change = roundf(change); 
	if(change < 0){
		printf("error: value should be more than or equal to 0\n");
		main();
		return 0;
	}
	while(change > 0){
		if(change >= 25){
			change = change - 25;
			t++;
		}
		else if(change >= 10){
			change = change - 10;
			t++;
		}
		else if(change >= 5){
			change = change - 5;
			t++;
		}
		else if(change >= 1){
			change = change - 1;
			t++;
		}
	} //While ends
	printf("%d\n", t);
	return 0;
} // main ends
