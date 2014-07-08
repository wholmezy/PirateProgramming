#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#define DECKSUIT 4
#define DECKNUM 14
#define DECKSIZE 52
////////////////////////////////////////////////////////////////////////////////////////
// Code for the reddit dailyprogrammer challange 5/5/2014 #161 [Easy] Blackjack!      //
// made by Wholmezy                                                                   //
// http://www.reddit.com/r/dailyprogrammer/comments/24r50l/552014_161_easy_blackjack  //
////////////////////////////////////////////////////////////////////////////////////////

typedef struct Card {
    int value;
    int suit;
} Card;

int main(int argc, char* argv[]){
	

	printf("Give me an integer between 1 and 10.\n");
	int numDecks; 
	scanf("%d", &numDecks);
	printf("\n");

    if(numDecks > 10 || numDecks < 1){
        return 1;
    }



    Card Deck[DECKSIZE + 1];

	//Giving a value and suit to every card in the deck. 
    int i, suit, value, counter;
	suit = 0;
	value = 0;
	counter = 0;
	int c;
	c = 0;
    for(i = 1; i <= DECKSIZE; i++){
        Deck[i].suit = suit;
		Deck[i].value = value;
		value++;
		counter++;
		c++;
		printf("DK.SIT = %d\nDK.VLE = %d\nDK.SZE = %d\n", Deck[i].suit, Deck[i].value, c);
		
		if(counter == 4){
			suit = (suit + 1)% 4;		
			counter = 0;
		}
		if(value == 13){value = 1;}
		
    }
	
	/*Card deckReal[530];
	int j;
	for(j = 0; j < numDecks; j++){
		
		int buffer;
		int z;
		for(z = 0; z < 52; z++){
			copy Deck[rand(0-52)] to buffer and make Deck[rand(0-52)] = NULL; 
			if(buffer == NULL){
				copy Deck[rand(0-52)] to buffer and make Deck[rand(0-52)] = NULL;
				Repeat this process until buffer != NULL
			}
			else{
				deckReal[z] = buffer;
			}
			repeat the process above until all the Decks are empty...


		}
		




	}*/



return 0;








}
