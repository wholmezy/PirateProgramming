/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char* argv[]){
	//Byte is for buffer.
	typedef uint8_t BYTE;
	//open file.
    FILE* card = fopen("card.raw", "r");
    //Name is jepg number.
    int name = 0;
	BYTE buffer[512];
	//title is the holder for the img file name.
	char title[8];
	//picture write loop.
	int readFlag = 1;
	int i = 0;
	for(int x = 0; x < 49;){
		//read in card values 512 bits at a time.
		if(readFlag == 1){
			fread(&buffer, sizeof(buffer), 1, card);
		}
		else{ readFlag = 1; }
		
		
		//checks if jpeg beginning is there...
		
		if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1) ){
			
			sprintf(title, "%03d.jpg", name);
			FILE* img = fopen(title, "w");
			int stop = 0;
			//Writes the pictures in a jpeg file.
			do{ 
				fwrite(&buffer, sizeof(buffer), 1, img);
				fread(&buffer, sizeof(buffer), 1, card); 
				//if the buffer goes to these requirements stop.
				i++;
				if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1)){
					stop++;
					x++;
					name++;
					fclose(img);
					readFlag = 0;
				}
				//Checks for end of file. EOF.
				else if(feof(card)){
					x++;
					fclose(img);
				}
			
			
			}
			//do while thing...
			while(stop == 0);
			

		} // if statement end.
			
			
	} // End of for-loop
		
}





