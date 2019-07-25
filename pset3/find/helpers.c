/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 // what to search for, in what array, of what size. 
bool search(int value, int values[], int n)
{
    int start = 0;
    int end = n - 1;
    int middle = (start + end) / 2;

    while (start <= end)
    {
        // see if middle number matches
        if (values[middle] == value) { return true; }
        
        // see if the values is bigger than mid value
        // if it is, search left.
        else if (value < values[middle])
        {
            end = middle - 1;
            middle = (start + end) / 2;
        }
        
        // if value is smaller than mid, search right.
        else if (value > values[middle])
        {
            start = middle + 1;
            middle = (start + end) / 2;
        }
        else { break; }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
 
 // input: array with values, size of array
void sort(int values[], int n)
{
    // initilize loop booleon
    bool loop;
    
    // loop as long as loop is equal to true
    do
    {
        // start of as false
        loop = false;
        
        // loop through array
        for (int i = 0; i < n-1; i++)
        {
            // if left number is larger, change place. 
            if (values[i] > values[i+1])
            {
                // save current value in a variable to reuse it correctly
                int value = values[i];
                
                // change values
                values[i] = values[i+1];
                values[i+1] = value;
                loop = true;
            }
        }
    // if there are no values left to itterate through
    // loop will stay as false and break the do-while
    } while(loop == true);
    
    return;
}

