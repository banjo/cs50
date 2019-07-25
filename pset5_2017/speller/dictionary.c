#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "dictionary.h"


// define size of HASH
#define HASH 100000

// nodes for linked list
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

// create hashtable
node* hashtable[HASH];

// create hash function
int hash (const char* word)
{
   // set index at 0
    int index = 0;

    // use ascii
    for (int i = 0; word[i] != '\0'; i++)
        // find lower case words
        index += tolower(word[i]);

    // stay within hash size
    return index % HASH;    
}

// variables to use later
int count = 0;
char word[LENGTH+1];

bool load(const char* dictionary)
{
    // open dictionary
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
        return false;
    
    // scan dict
    while (fscanf(dict, "%s\n", word)!= EOF)
    {
        // memory for new word
        node* newWord = malloc(sizeof(node));
        
        // copy word to node
        strcpy(newWord->word, word);
        
        // find what index of the array the word should go in
        int index = hash(word);
        
        // if hashtable is empty, insert new word
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        
        // if hastable is not empty
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }
        
        // increase count
        count++;
    }
    
    // close dict
    fclose(dict);
    
    return true;
}


bool check(const char* word)
{
    // get a lower case of the word
    char lower[LENGTH + 1];
    int len = strlen(word);
    for(int i = 0; i < len; i++) { lower[i] = tolower(word[i]); }
    lower[len] = '\0';
    
    // create index from the word
    int index = hash(lower);
    
    // look at the hashtable at position of index
    if (hashtable[index] == NULL) { return false; }
    
    // create cursor
    node* cursor = hashtable[index];
    
    // while hashtable is not empty, compare words
    while (cursor != NULL)
    {
        if (strcmp(lower, cursor->word) == 0) { return true; }
        cursor = cursor->next;
    }
    
    // if no word; return false
    return false;
}

unsigned int size(void) { return count; }

bool unload(void)
{
    // create a counter
    int counter = 0;
    
    // iterate from counter to the defined size
    while (counter < HASH)
    {
        // if empty at number of counter, increment it
        if (hashtable[counter] == NULL) { counter++; }
        
        // if its not empty, go thorugh and free memory
        else
        {
            while(hashtable[counter] != NULL)
            {
                node* cursor = hashtable[counter];
                hashtable[counter] = cursor->next;
                free(cursor);
            }
            
            // when it is empty, increment counter
            counter++;
        }
    }
    
    return true;
}