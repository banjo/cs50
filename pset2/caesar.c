#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encipher(int character, bool upper, int key);

int main(int argc, string argv[])
{
    // check if there is 2 argvs.
    if (argc != 2)
    {
        // error message 
        printf("error: only 2 argvs\n");
        return 1;
    }
    
    // convert input from string to int. 
    int key = atoi(argv[1]);
    
    // prompt for plaintext. 
    printf("plaintext: ");
    string s = get_string();
    
    // check that input is not NULL
    if (s != NULL)
    {
        printf("ciphertext: ");
        
        // itarate thorugh chars in input.
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // check if it is an aplhabetic letter.
            if (isalpha(s[i]))
            {
                // enchiper upper.
                if (isupper(s[i])) { encipher(s[i], true, key); }
                
                // enchiper lower.
                else if (islower(s[i])) { encipher(s[i], false, key); }
            }
            // add other characters. 
            else { printf("%c", s[i]); }
        }
    printf("\n");
    return 0;
    }
}


void encipher(int character, bool upper, int key)
{
    // encipher upper case characters.
    if (upper == true)
    {
        // formula
        int convert = (((character - 65) + key) % 26) + 65;
        printf("%c", convert);
    }
    
    // encipher lower case characters.
    else if (upper == false)
    {
        // formula
        int convert = (((character - 97) + key) % 26) + 97;
        printf("%c", convert);
    }
}

