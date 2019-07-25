/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // variable to make it look cleaner later when changing places
    int index = d-1;
    
    // counter that start at highest value possible
    // which will count down and add each number
    // of itself to array
    int max = d * d - 1;
    
    // iterate over the array to add all numbers
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = max;
            max--;
        }
    }
    
    // if dimension is even, change 0 and 1
    if(d % 2 == 0)
    {
        // change places
        int change = board[index][index-1];
        board[index][index-1] = board[index][index-2];
        board[index][index-2] = change;
    }
    
    // zero will be given '_' or the ascii value 95
    // board[d-1][d-1] = '_';
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // print new line to make it look clearer
    printf("\n");
    
    // itterate of array to print out all numbers.
    for (int i = 0; i < d; i++)
    { 
        for (int j = 0; j < d; j++)
        {
            // print out underline for the value 95, which is zero
            if (board[i][j] == 0) { printf(" _ "); }
            
            // print out the other numbers
            else { printf("%2d ", board[i][j]); }
        }
    printf("\n");
}
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int location;
    int underscore;
    
    // check input value
    if (tile > (d * d - 1))
    {
        return false;
    }
    
    // find location of input
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                // the located tile will be used later on in a variable
                location = board[i][j];
                break;
            }
        }
    }
    
    // find location of underscore, and then change it with given tile if possible
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // check where underscore is
            if (board[i][j] == 0)
            {
                // attach it to a variable to properly exchange values
                underscore = board[i][j];
                
                // if tile is under, exchange
                if (location ==  board[i+1][j])
                {
                    board[i][j] = board[i+1][j];
                    board[i+1][j] = underscore;
                    return true;
                }
                // if tile is over, exchange
                else if (location == board[i-1][j])
                {
                    board[i][j] = board[i-1][j];
                    board[i-1][j] = underscore;
                    return true;
                }
                // if tile is to the right, exchange
                else if (location == board[i][j+1])
                {
                    board[i][j] = board[i][j+1];
                    board[i][j+1] = underscore;
                    return true;
                }
                // if tile is to the left, exchange
                else if (location == board[i][j-1])
                {
                    board[i][j] = board[i][j-1];
                    board[i][j-1] = underscore;
                    return true;
                }
                // else, return false
                return false;
                break;
            }
        }
    }
    return 0;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int start = 1;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (start == (d*d - 1))
            {
                return true;
            }
            else if (board[i][j] == start)
            {
                start++;
                continue;
            }
        }
    }
    return false;
}
