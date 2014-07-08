/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // If there isnt a second or/and third line after ./generate print a error message.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Creates an integer which has the value of the first strings ascii value, 
    // for example 1 has 1 as int value.
    int n = atoi(argv[1]);

    // If there is a third line in the command promt, make the int value of that line into the seed for the rand function. if there isnt a third line use the seed 1 to pseudo randomize.
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // Prints a random number n number of times where n is the atoi value of the second line in the cmd promt and the number repeats after going above 65536 by modulus '%'.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks. ok.
    return 0;
}
