/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define HASHSIZE 500

typedef struct node{

        char word[LENGTH + 1];
        struct node* next;

} node;

int dictionarySize = 0;
node* hashTable[HASHSIZE];

int hash(char* hashWord){

    int index = 0;
    for(int i = 0; i < strlen(hashWord); i++){
        index = index + (int)hashWord[i];
    }

    return index % HASHSIZE;

}



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* newWord){
    //first make whole word into lowercase word.
    char* word = malloc(sizeof(char[LENGTH + 1]));
    strcpy(word, newWord);
    for(int i = 0; i < strlen(word); i++){
    	word[i] = tolower(word[i]);
    }
    //get hash index to see where word should be.
    int index = hash((char*)word);
    node* cursor;
    cursor = hashTable[index]->next;
    int comparer;

    while(cursor != NULL){
    	comparer = strcmp(word, cursor->word);
        if(comparer == 0){
        	
        	free(word);
            return true;
        }
        cursor = cursor->next;
    }

	free(word);
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary){

    FILE* dic = fopen(dictionary, "r");
    if(dic == NULL){
        printf("Could not load dictionary\n");
        return false;
    }
    
    //initiate hashtable to make all pointers point to NULL.
    for(int i = 0; i < HASHSIZE; i++){
        hashTable[i] = (node*)malloc(sizeof(node));
        hashTable[i]->next = NULL;
    }

    //index value for where in the hashtable to put the word.
    int index;
    //current is a pointer that helps inserting new nodes.
    node* current;
	char wordBuffer[LENGTH + 1];
	//Word placement loop.
    while(fscanf(dic, "%s", wordBuffer) != EOF){
        //make word lowercase to make it easier to check later on.
        for(int i = 0; i < strlen(wordBuffer); i++){
    		wordBuffer[i] = tolower(wordBuffer[i]);
    	}
        index = hash(wordBuffer);
        //counter for how many words there are in the dictionary.
        dictionarySize++;
        current = hashTable[index]->next;
        node* new_node = (node*)malloc(sizeof(node));
        if(new_node == 0){
            printf("Out of memory\n");
            return false;
        }
        strcpy(new_node->word, wordBuffer);

        new_node->next = hashTable[index]->next;
        hashTable[index]->next = new_node;

        current = hashTable[index];
    }
    fclose(dic);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void){
    return dictionarySize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void){
	node* temp;
    for(int i = 0; i < HASHSIZE; i++){
        node* cursor;
        cursor = hashTable[i];
        while(cursor != NULL){
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        
    }
    return true;
}
