#include <stdio.h>

/* ******************************************************************************************************
*	http://www.reddit.com/r/dailyprogrammer/comments/17jvoh/013013_challenge_119_intermediate_find_the/ *
*	Written by Pirate Programmer(wholmezy) on (Finished*(A PROGRAM IS NEVER FINISHED))2014-05-31        *
*	blog = http://pirateprogramming.tumblr.com/ gitHub = https://github.com/wholmezy/PirateProgramming  *
*********************************************************************************************************/

#define MAP 20
#define STARTVALUE 0

int main(){
	//struct for mapGrid with coordinate integer value and char coordinate.
	typedef struct chart{
        char chartChar;
        int chartValue;

	}chart;

	int mapSizeInput;

	printf("Give me the size of the map as a square, ex 5 which equals 5x5\nMaxiumum size is 20\n");
	scanf("%i", &mapSizeInput);
    //make sure the mapsize is right.
	if(mapSizeInput >= MAP || mapSizeInput <=  1){
		printf("Wrong map size\n");
		return 1;
	}

    const int mapSize = mapSizeInput;

	chart mapGrid[mapSize][mapSize];
	//Get map input.
	printf("Write one letter at a time to paint make the map\n\ns = start\ne = end\n. = walkway\nw = wall\n\n");
	for(int i = 0; i < mapSize; i++){
		for(int j = 0; j < mapSize; j++){
			scanf(" %c", &mapGrid[i][j].chartChar);
			mapGrid[i][j].chartValue = STARTVALUE;
		}
	}
    // x and y coordinates for array.
    int posi1;
    int posi2;
    // buffer for x and y coordinates
    int posi1Buf;
    int posi2Buf;
	//Print map and get start position
	for(int z = 0; z < mapSize; z++){
		printf("\n");
		for(int x = 0; x < mapSize; x++){
            printf("%c", mapGrid[z][x].chartChar);
            if(mapGrid[z][x].chartChar == 's'){
                posi1Buf = z;
                posi2Buf = x;
            }
		}
	}
	printf("\n\n");
    //If while position gets stuck, give up.
    int timer = 0;
    //bools to stop the while loop.
    int pf1 = 1;
    int pf2 = 1;
    //If the loop goes above the counter it restarts.
    int counterBuf;
    int counter;
    //make sure to not check counterBuf before first find.
    int first = 0;
    //compare values of coordinates.
    int compare;
    //bool to make sure it does not put counterBuf into counter if it gets stuck.
    int fullMapFlag;
    //directions available.
    enum wasd{STOP, RIGHT, DOWN, LEFT, UP};
    wasd direction = STOP;
    //path finding loop for every path taken.
    while(pf1 == 1){
        //set start position.
        posi1 = posi1Buf;
        posi2 = posi2Buf;
        //reset while loop 2.
        pf2 = 1;
        //rewrite counterBuf.
        counterBuf = 0;
        fullMapFlag = 0;
        //direction if none is available.
        direction = STOP;
        //make a path.
        while(pf2 == 1){
            //Force stop if it gets stuck.
            if(counterBuf >= (mapSize * mapSize)){
                pf2 = 0;
                timer++;
                fullMapFlag = 1;
            }
            //Make sure every time is faster than the one before.
            else if(counterBuf >= counter && first == 1){
                pf2 = 0;
                timer++;
                fullMapFlag = 1;
            }
            //make sure coordinates does not leave the grid.
            else if(posi1 > mapSize || posi2 > mapSize){ pf2 = 0; fullMapFlag = 1;}
            else{
                //Check if current position is goal.
                if(mapGrid[posi1][posi2].chartChar == 'e'){
                    pf2 = 0;
                    timer = 0;
                    printf("Win!\n");
                }
                //if it does not finish right 20 times in a row, finish both loops.
                else if(timer >= 20){
                    pf1 = 0;
                    pf2 = 0;
                }
                else{
                    //Compare which direction has been moved the least, then change direction towards that. the first if statement is a boundary check.
                    if(mapGrid[posi1][posi2 + 1].chartChar == '.' || mapGrid[posi1][posi2 + 1].chartChar == 'e' && posi2 < mapSize - 1){
                        compare = mapGrid[posi1][posi2 + 1].chartValue;
                        direction = RIGHT;
                    }
                    else if(mapGrid[posi1 + 1][posi2].chartChar == '.' || mapGrid[posi1 + 1][posi2].chartChar == 'e' && posi1 < mapSize - 1){
                        compare = mapGrid[posi1 + 1][posi2].chartValue;
                        direction = DOWN;
                    }
                    else if(mapGrid[posi1][posi2 - 1].chartChar == '.' || mapGrid[posi1][posi2 - 1].chartChar == 'e' && posi2 > 0){
                        compare = mapGrid[posi1][posi2 - 1].chartValue;
                        direction = LEFT;
                    }
                    else if(mapGrid[posi1 - 1][posi2].chartChar == '.' || mapGrid[posi1 - 1][posi2].chartChar == 'e' && posi1 > 0){
                        compare = mapGrid[posi1 - 1][posi2].chartValue;
                        direction = UP;
                    }
                    if(posi1 < mapSize - 1){
                        if(mapGrid[posi1 + 1][posi2].chartChar == '.' || mapGrid[posi1 + 1][posi2].chartChar == 'e'){
                            if(mapGrid[posi1 + 1][posi2].chartValue <= compare){
                                compare = mapGrid[posi1 + 1][posi2].chartValue;
                                direction = DOWN;
                            }
                        }
                    }
                    if(posi2 > 0){
                        if(mapGrid[posi1][posi2 - 1].chartChar == '.' || mapGrid[posi1][posi2 - 1].chartChar == 'e'){
                            if(mapGrid[posi1][posi2 - 1].chartValue <= compare){
                                compare = mapGrid[posi1][posi2 - 1].chartValue;
                                direction = LEFT;
                            }
                        }
                    }
                    if(posi1 > 0){
                        if(mapGrid[posi1 - 1][posi2].chartChar == '.' || mapGrid[posi1 - 1][posi2].chartChar == 'e'){
                            if(mapGrid[posi1 - 1][posi2].chartValue <= compare){
                                compare = mapGrid[posi1 - 1][posi2].chartValue;
                                direction = UP;
                            }
                        }
                    }
                    //change coordinates to where the direction is pointing.
                    switch(direction) {
                        case RIGHT:
                            posi2++;
                            counterBuf++;
                            mapGrid[posi1][posi2].chartValue++;
                            break;
                        case DOWN:
                            posi1++;
                            counterBuf++;
                            mapGrid[posi1][posi2].chartValue++;
                            break;
                        case LEFT:
                            posi2--;
                            counterBuf++;
                            mapGrid[posi1][posi2].chartValue++;
                            break;
                        case UP:
                            posi1--;
                            counterBuf++;
                            mapGrid[posi1][posi2].chartValue++;
                            break;
                        default:
                            printf("Did not move.\n");
                            pf2 = 0;
                            pf1 = 0;
                            timer = 100;
                    }
                }
            }
        }
        if(pf1 == 1 && fullMapFlag == 0){
            counter = counterBuf;
            for(int z = 0; z < mapSize; z++){
                printf("\n");
                for(int x = 0; x < mapSize; x++){
                    printf("%d", mapGrid[z][x].chartValue);
                }
            }
            printf("\n\n");
        }
        first = 1;

    }
    for(int z = 0; z < mapSize; z++){
        printf("\n");
        for(int x = 0; x < mapSize; x++){
            printf("%d", mapGrid[z][x].chartValue);
        }
    }
    printf("\n\nshort path = %d steps\n", counter);
}
