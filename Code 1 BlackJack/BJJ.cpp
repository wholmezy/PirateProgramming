#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#define DECKSUIT 4
#define DECKNUM 13
#define DECKSIZE 52
////////////////////////////////////////////////////////////////////////////////////////
// Code for the reddit dailyprogrammer challange 5/5/2014 #161 [Easy] Blackjack!      //
// written by Wholmezy                                                                //
// http://www.reddit.com/r/dailyprogrammer/comments/24r50l/552014_161_easy_blackjack  //
////////////////////////////////////////////////////////////////////////////////////////

typedef struct Card {
    int value;
    int suit;
} Card;

int main(int argc, char* argv[]){
	int numDecks;
	int g = 1;
	while(g == 1){
		printf("Give me an integer between 1 and 10.\n");
		scanf("%d", &numDecks);
		printf("\n");
		if(numDecks <= 10 && numDecks >= 1){
			g = 0;
		}
		else{ printf("FALUT VALUE\n"); }
	}



    Card Deck[DECKSIZE + 1];

	//Giving a value and suit to every card in the deck.


	Card deckReal[521];
	int j;
	int rnd1;
	int y;
	int z;
	int repeater;
	srand((unsigned)time(NULL));
	Card buffer;
	//Fill the real deck with random cards from up to ten other decks.
	for(j = 0; j < numDecks; j++){
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
			//printf("DK.SIT = %d\nDK.VLE = %d\nDK.SZE = %d\n", Deck[i].suit, Deck[i].value, c);

			if(counter == 4){
				suit = (suit + 1)% 4;
				counter = 0;
			}
			if(value == 13){value = 1;}
		}
		int z;
		for(z = 0; z < DECKSIZE; z++){
			repeater = 1;
			while(repeater == 1){
				rnd1 = rand() % 52;
				//printf("%d\n", rnd1);
				buffer = Deck[rnd1];
				Deck[rnd1].suit = NULL;
				Deck[rnd1].value = NULL;
                if(buffer.value != NULL){
					deckReal[z] = buffer;
					z++;
					repeater = 0;
				}
			}
		}
	} //for loop ends.

	//get two random cards from the deck and add them.
	printf("How many doubles of cards do I give out before you get a result?\n");
    int ctg = 0;
    scanf("%d", &ctg);
    int m;
    Card buffer2[2];
    int t;
    int m2 = 0;
    int m3 = 0;
    int rnd2;
    for(m = 0; m < ctg; m++){
        repeater = 1;
        for(t = 0; t < 2; t++){
			repeater = 1;
            while(repeater == 1){
                rnd2 = rand() % 520;
                if(deckReal[rnd2].value < 13 && deckReal[rnd2].value >= 0){
					buffer2[t].value = deckReal[rnd2].value;
                    repeater = 0;
                }
            }


        }
        Card h;
		if(buffer2[0].value > 9){ buffer2[0].value = 10; }
		if(buffer2[1].value > 9){ buffer2[1].value = 10; }
		if(buffer2[0].value == 1){ buffer2[0].value = 11; }
		if(buffer2[1].value == 1){ buffer2[1].value = 11; }
		h.value = buffer2[0].value + buffer2[1].value;
		//printf("%d + %d = %d\n", buffer2[0].value, buffer2[1].value, h.value);
        if(h.value == 20){ m2++; }
        else{ m3++; }

		
    }
    int chance;
    chance = (((m2 * 100) / (m3)));
    printf("The percentage chance to get the value 21 out of %d decks and %d card deals is %d percent\n", numDecks, ctg, chance);
	return 0;
}
