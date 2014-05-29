#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************************************************
** Recipe app that gets a recipe as input and outputs the same recipe with changed number of ingredients depending on the amount of people   ****
** the input wants it to be for.																											 ****
** Written by Wholmezy.																														 ****
*************************************************************************************************************************************************/

int main(){

	//amount of people in the recipe and wanted for new recipie.
	int ppl;
	printf("For how many people is the recipe?\n");
	scanf("%d", &ppl);
	printf("\n");

	int newPpl;
	printf("For how many people do you want the recipe to be for?\n");
	scanf("%d", &newPpl);
	printf("\n");

	//Self-explanatory
	printf("Press . to cancel.\nPress , to finish.\n\n");

	bool doneFlag = true;

	//incr is for the forloop later. Ingnum is the ingredient number.
	int incr = 0;
	int ingnum = 1;

	//numBuff is buffer for number of ingredients while prefNum is the opposite.
	float numBuff[20];
	char prefNum[10];

	//ingredient stores the buffer for the name of the ingredient and what measure it is ingredPrnt is the opposite.
	char ingredient[100];
	char ingredPrnt[20][100];

	while(doneFlag == true){

		//self-explanatory
		printf("How many of the measure are there for ingredient number %d?\n", ingnum);
		scanf("%s", &prefNum);

		//checks if the program should finish asking for new recipe pieces or just quit.
		if(prefNum[0] == '.'){ return 0; }
		if(prefNum[0] == ','){ doneFlag = false; }
		else{
			//make numBuff get the number of the specific ingredient then ask for the rest of the information.
			numBuff[incr] = atof(prefNum);
			printf("Give me the rest of the information; The measure and ingredient name!\n");
			scanf(" %[^\n]", ingredient);

			if(ingredient[0] == '.'){ return 0; }
			if(ingredient[0] == ','){ doneFlag = false; }

			strcpy(ingredPrnt[incr], ingredient);

			ingnum++;
			incr++;
		}
	}
	//self-explanatory
	printf("Here is your newly improved recipe!\n\n");
	int i;
	for(i = 0; i < incr; i++){
		numBuff[i] = ((numBuff[i] / ppl) * newPpl);
		printf("%.2f %s\n", numBuff[i], ingredPrnt[i]);


	}
}
