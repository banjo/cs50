#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encipher(string plaintext, string keyword);
void usage(void);

int main(int argc, string argv[])
{
    // check if there are 2 argvs.
    if (argc != 2)
    {
        // usage instructions
        usage();
        return 1;
    }
    
    // name input keyword.
    string keyword = argv[1];
    
    // itarate through keyword to see if it is only alphabetical characters. 
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        // if it is NOT alphabetical, return usage instructions.
        if (!isalpha(keyword[i]))
        {
            // usage instructions
            usage();
            return 1;
        }
    }
    
    // prompt for plaintext. 
    printf("plaintext: ");
    string s = get_string();
    
    // check that input is not NULL
    if (s != NULL)
    {
        // UX
        printf("ciphertext: ");
        
        // encipher function 
        encipher(s, keyword);
        
        printf("\n");
        return 0;
    }
}


void encipher(string plaintext, string keyword)
{
    // get lenght of the keyword for itteration. 
    int keyLength = strlen(keyword);
    
    // itterate through user plaintext. 
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        // get key for letter
        int letter = tolower(keyword[j % keyLength]) - 'a';
        
        // check if alphabetical. 
        if (isalpha(plaintext[i]))
        {
            // encipher upper case characters.
            if (isupper(plaintext[i]))
            {
                // encipher wih vigenere, print out the outcome. 
                char encipher = 'A' + (plaintext[i] - 'A' + letter) % 26;
                printf("%c", encipher);
            }
            
            // encipher lower case characters. 
            else
            {
                // encipher with vigenere, print out outcome.
                char encipher = 'a' + (plaintext[i] - 'a' + letter) % 26;
                printf("%c", encipher);
            }
            // increment j for every correct char that is used. 
            j++;
        }
        // print other characters, such as space, dot, etc. 
        else { printf("%c", plaintext[i]); }
    }
}

void usage(void)
{
    // usage instructions
    printf("Usage: vigenere <keyword>\n");
}

