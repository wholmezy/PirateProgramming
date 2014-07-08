#include<cs50.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, string argv[]){

	/* ERROR MESSAGES HERE */
	if(argc > 2){
		printf("You can only print 1 line after ./vgenere\n");
		return 1;
	}
	if(argv[1] == NULL){
		printf("You need one line after ./vigerne\n");
		return 1;
	}
	
	/* TO HERE   */
	string key = argv[1];
	int j = 0;
	int OffsetSmall = 97;
	int OffsetBig = 65;
	
	/* errorcheck here aswell!*/
	for(int error = 0; error < strlen(key); error++){
		if(key[error] < 65 || (key[error] > 90 && key[error] < 97) || key[error] > 122){
			printf("You can only have alphabetical characters in the key!\n");
			return 1;
		}
	
	}
	/* Ends here!*/
	string input = GetString();
	int mode[strlen(input)];
	for(int i = 0; i < strlen(input); i++){
		mode[i] = key[j];
		
		if(mode[i] > 'A' - 1 && mode[i] < 'Z' + 1){ //Makes uppercase keys lowercase.
			mode[i] = (((mode[i] - 65) + OffsetSmall)); 
		}
		if(input[i] > 96 && input[i] < 123){ //Encrypts lowercase letters!
			printf( "%c", ( ( (input[i]-OffsetSmall) + (mode[i]-OffsetSmall)) % 26) + OffsetSmall);
			j++;
		}
		else if(input[i] > 'A' - 1 && input[i] < 'Z' + 1){ //Encrypts uppercase letters!
			input[i] = input[i] + 32;
			printf( "%c", ( ( (input[i]-OffsetSmall) + (mode[i]-OffsetSmall)) % 26) + OffsetBig);
			j++;
		}
		else{ //prints everything else.
			printf("%c", input[i]);
		}
		
		if(j >= strlen(key)) {j = 0;} //j makes the key follow the input word/words.
		
	}
	printf("\n");
	
	
}
