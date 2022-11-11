#include <stdio.h>
#include <stdlib.h>

void draw(int height);

int total_height;
int aux;

int main(int argc, char *argv[])
{
    int height = atoi(argv[1]);
    total_height = height;

    draw(height);
}

// Comment one of the below functions
// Even Pyramid 
// void draw (int height)
// { 
//     if (height == 0)
//     {
//         return;
//     }

//     draw(height - 1);

//     int spaces = total_height - height;
//     for (int i = 1; i <= spaces; i++)
//     {
//         printf(" ");
//     }
//     for (int i = 1; i <= height; i++)
//     {
//         printf("#");
//     }
//     for (int i = 0; i <= height; i++)
//     {
//         printf("#");
//     }
//     printf("\n");
// }

// Odd pyramid
void draw (int height)
{ 
    if (height == 0)
    {
        return;
    }

    draw(height - 1);

    int spaces = total_height - height;
    for (int i = 1; i <= spaces; i++)
    {
        printf(" ");
    }
    for (int i = 1; i <= height + aux; i++)
    {
        printf("#");
    }
    aux++;
    printf("\n");
}