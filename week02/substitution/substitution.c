#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// This program encrypts a message using a substitution cipher.

bool only_letters(string s);
char replace_letters(char letter, string key);
bool repeated_characters(string s);

int main(int argc, string argv[])
{
    // Prints an error if anything other than only one argument is given.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Prints an error if the number of characters in the key is different from 26.
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Prints an error if there are any non-letter characters in the key.
    if (!only_letters(argv[1]))
    {
        printf("Key must must be composed only of letters.\n");
        return 1;
    }
    // Prints an error if there are repeated characters in the key.
    if (repeated_characters(argv[1]))
    {
        printf("The key can't have repeated alphabet letters (case-insensitive).\n");
        return 1;
    }
    // Gets the plaintext.
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    // Prints the corresponding ciphertext.
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", replace_letters(plaintext[i], argv[1]));
    }
    printf("\n");
    return 0;
}
// Returns false if one of the string's characters isn't a letter.
bool only_letters(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}
// Returns true if there are repeated characters in a string.
bool repeated_characters(string s)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int counter;
    for (int i = 0; i < strlen(alphabet); i++)
    {
        counter = 0;
        for (int j = 0; j < strlen(s); j++)
        {
            s[j] = tolower(s[j]);
            if (alphabet[i] == s[j])
            {
                counter++;
                if (counter > 1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
// Replaces the letter according to the key.
char replace_letters(char letter, string key)
{
    char substitute_letter;
    // The character will only be changed if it's a letter.
    if (isalpha(letter))
    {
        // Distinct commands are necessary for upper and lower case letters.
        if (isupper(letter))
        {
            // String containing the upper case alphabet.
            string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for (int i = 0; i < strlen(key); i++)
            {
                // Compares the current letter to every upper alphabet letter.
                if (letter == upper_alphabet[i])
                {
                    // Receives the letter positioned correspondingly in the key.
                    substitute_letter = toupper(key[i]);
                    return substitute_letter;
                }
            }
        }
        // Same idea but for lower case.
        else
        {
            string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < strlen(key); i++)
            {
                if (letter == lower_alphabet[i])
                {
                    substitute_letter = tolower(key[i]);
                    return substitute_letter;
                }
            }
        }
    }
    return letter;
}