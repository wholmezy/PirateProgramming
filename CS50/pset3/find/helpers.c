/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include<stdio.h>
#include<math.h>
#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n){
    int x = 2;
    int timer = n;
    int a = n / x;
    while(timer > 0){
    	timer--;
    	x = x + 2;
    	if(value == values[a]){return true;}
    	if(value < values[a]){
    		a = a / x;
    		a = round(a);
    	}
    	else if(value > values[a]){
    		a = a + ((n + 1) /x);
    		a = round(a);
    	}
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i = 0; i < n - 1; i++){
    	for(int j = 0; j < n - 1; j++){
    		if(values[j] > values[j+1]){
    			int StoreA = values[j];
    			int StoreB = values[j+1];
  				values[j] = StoreB;
    			values[j+1] = StoreA;
    		}
    	}
    	 
    }
    return;
}






