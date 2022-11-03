#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Asks for the pyramid's height at least once.
    do
    {
        height = get_int("Enter an integer number from 1 through 8 to be the pyramid's height: ");
    }
    // If the inserted height is not in the 1-8 range, repeat.
    while (height < 1 || height > 8);
    // Iterate from i (counter) through height.
    for (int i = 1; i <= height; i++)
    {
        // The spaces to be printed are defined by height minus counter as the length of characters will always be equal to the height but the number of hashes will gradually increase, thus making the spaces decrease.
        int spaces = height - i;
        // j is just a secondary counter in both cases bellow.
        for (int j = 1; j <= spaces; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}