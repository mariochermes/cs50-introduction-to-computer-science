#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// This program receives a key as an argument and encrypts an inputted message using it.

bool only_digits(string arg);
char rotate(char letter, int n);
string alphabet(bool upper);

int main(int argc, string argv[])
{
    // Will issue an error in case there isn't exactly one argument.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Will issue an error if the argument isn't a number.
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Transforms the argument into an int variable.
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    // Displays the rotated letters.
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
    return 0;
}
// Returns false if one of the string's characters isn't a digit.
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
// Rotates the letter by n positions.
char rotate(char letter, int n)
{
    char rotated_letter = '\0';
    // letter_index is the corresponding alphabet index of a letter in the ASCII table.
    int letter_index;
    // If the key is higher than 26, it's remainder by 26 will become the key to properly wrap around from z to a.
    if (n > 26)
    {
        n = n % 26;
    }
    // The character will only be changed if it's a letter.
    if (isalpha(letter))
    {
        // Distinct commands are necessary for upper and lower case letters.
        if (isupper(letter))
        {
            // String containing the upper case alphabet.
            string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            // Subtraction from 65 as it represents "A" in the ASCII table.
            letter_index = letter - 65;
            // If the index plus the key is high enough to overlap the index will be subtracted by 26.
            if (letter_index + n >= 26)
            {
                letter_index = letter_index + n - 26;
                rotated_letter = upper_alphabet[letter_index];
            }
            else
            {
                letter_index = letter_index + n;
                rotated_letter = upper_alphabet[letter_index];
            }
            return rotated_letter;
        }
        // Same ideia as above but with "a" starting at 97 in the ASCII table.
        else
        {
            string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
            letter_index = letter - 97;
            if (letter_index + n >= 26)
            {
                letter_index = letter_index + n - 26;
                rotated_letter = lower_alphabet[letter_index];
            }
            else
            {
                letter_index = letter_index + n;
                rotated_letter = lower_alphabet[letter_index];
            }
            return rotated_letter;
        }
    }
    return letter;
}
