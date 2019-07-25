#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{   
    // check for only 1 argc
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover <filename>\n");
        return 1;
    }
    
    // name the inputed file
    char *file = argv[1];
    
    // open file and safe check
    FILE *inputfile = fopen(file, "r");
    if (inputfile == NULL)
    {
        fprintf(stderr, "Can't read file\n");
        return 2;
    }
    
    
    uint8_t buffer[512];
    int filecounter = 0;
    FILE *outfile = NULL;
    
    // read file
    while (fread(buffer, 512, 1, inputfile))
    {
        // check first bytes
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // close if it is opened
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            
            // create new file
            char filename[8];
            sprintf(filename, "%03d.jpg", filecounter);
            
            // new jpeg file
            outfile = fopen(filename, "w");
            
            // increase counter
            filecounter++;
        }
        
        // write picture to file
        if (outfile != NULL)
        {
            fwrite(buffer, 512, 1, outfile);
        }
    }
    
    
    if (outfile != NULL)
    {
        fclose(outfile);
    }
    
    fclose(inputfile);
    return 0;

}