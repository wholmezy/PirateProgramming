#include <stdio.h>
#include <cs50.h>
    
int main(void){
    printf("write a number between 0-23 and i will write a halfpyramid with that many floors!\n");
    // x is number of floors
    int x = GetInt();
    //u & n helps with number of times since x changes after every while loop.
    int u = x;
    int g = 0;
    int t = 2;
    int n = x;
    int q = 1;
    if(x < 24 && x >= 0){
        while(u > 0){
            u--;
            //^ number of times the for function is used.
            for (int i = 0 ; i < n - q; i++){
                printf(" ");
            }
            while(g < t){
                printf("#");
                g++;
            }
            q++;
       		g = 0;
        	t++;
        	printf("\n");
        	x++;
        }

            
    }
    else {
        main();
    }     
    return 1;  
}
