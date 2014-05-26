#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int ppl;
	printf("For how many people is the recipie?\n");
	scanf("%d", &ppl);

	int newPpl;
	printf("For how many people do you want the recipie to be for?\n");
	scanf("%d", newPpl);
	
	printf("Press q to cancel.\nPress d to finish.\n");

	bool doneFlag = true;

	int incr = 0;
	int ingnum = 1;

	int numBuff[20];
	char prefNum[10];

	char ingredient[100];
	char ingredPrnt[20][100];

	while(doneFlag == true){

		printf("lol\n");

		printf("How many of the measure are there for ingredient number %d?\n", ingnum);

		scanf("%s", &prefNum);
		if(prefNum[0] == 'q'){ return 0; }
		if(prefNum[0] == 'd'){ doneFlag = false; }
		else{
			numBuff[incr] = atoi(prefNum);
			printf("%d\n", numBuff[incr]);
			printf("Give me the rest of the information; The measure and ingredient name!\n");

			scanf(" %[^\n]", ingredient);
			if(ingredient[0] == 'q'){ return 0; }
			if(ingredient[0] == 'd'){ doneFlag = false; }

			strcpy_s(ingredPrnt[incr], sizeof(ingredient), ingredient);
			printf("%s\n", ingredPrnt[incr]);
			printf("%s\n", ingredPrnt[0]);

			ingnum++;
			incr++;
		}
	}


	printf("Here is your newly improved recipie!\n\n");
	int i;
	for(i = 0; i < incr; i++){
		numBuff[i] = ((numBuff[i] / ppl) * newPpl);
		printf("%d %s\n", numBuff[i], ingredPrnt[i]);


	}




}
