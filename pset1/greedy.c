#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int count = 0;
    
    do
    {
        printf("Price in dollars: ");
        dollars = get_float();
    }
    while(dollars < 0);
    
    int cents = round(dollars * 100);
    
    while(cents >= 25) { count += 1; cents = cents - 25; }
    
    while(cents >= 10) { count += 1; cents = cents - 10; }
    
    while(cents >= 5) { count += 1; cents = cents - 5; }
    
    while(cents >= 1) { count += 1; cents = cents - 1; }
    
    printf("%i\n", count);

}