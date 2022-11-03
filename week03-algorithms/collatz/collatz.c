#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int collatz(int n);

int main (int argc, string argv[1])
{
    printf("%i\n", collatz(atoi(argv[1])));
}

int collatz (int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if ((n % 2) == 0)
    {
        return 1 + collatz(n / 2);
    }
    else
    {
        return 1 + collatz(3 * n + 1);
    }
}