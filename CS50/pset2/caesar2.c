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
			if(code[i] > 96 && code[i] < 123){
			printf("%c", ((code[i]+key-19) % 26) + 97 );
			}
			else if(code[i] > 64 && code[i] < 91){
			printf("%c", ((code[i]+key-13) % 26) + 65);
			}
		}
		printf("\n");
	} 
	else {
		printf("error, invalid encryption key\n");
		return 1;
	}
}


				//printf("%c", code[i]);
/*				if(code[i] > 96 && code[i] < 123){
					code[i] = code[i] + key;
					printf("%c", code[i]);
					while(code[i] > 123){
						code[i] = code[i] - 26;
					}
				}
				else if(code[i] > 64 && code[i] < 91){
					code[i] = code[i] + key;
					printf("%c", code[i]);
					while(code[i] > 91){
						code[i] = code[i] - 26;
					}
				}
*/
