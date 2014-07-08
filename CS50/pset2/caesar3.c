#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, string argv[]){
	int key = atoi(argv[1]);
	if(key >= 0){
		string code = GetString();
		int n = strlen(code);
		for(int i = 0; i < n; i++){
			if(code[i] > 96 && code[i] < 123){ //prints small letters
			printf("%c", ((code[i]+key-19) % 26) + 97 );
			}
			else if(code[i] > 64 && code[i] < 91){ //prints capital letters
			printf("%c", ((code[i]+key-13) % 26) + 65);
			}
			else if(code[i] == ' '){ //Prints spaces.
			printf(" ");
			}
			else{
				printf("%c", code[i]);
			}
		}
		printf("\n");
	}
	else {
		printf("error, invalid encryption key\n");
		return 1;
	}
}
