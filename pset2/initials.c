#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // ask user for input, save as name.
    string name = get_string();
    
    // make sure get_string returns a string
    if (name != NULL)
    {
        // prints the first initial in upper case.  
        printf("%c", toupper(name[0]));
        
        // iterate through the input string. 
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            // if there is a space, print the coming letter in upper case. 
            if (name[i] == ' ')
            {
                printf("%c", toupper(name[i + 1]));
            }
        }
    }
    printf("\n");
}