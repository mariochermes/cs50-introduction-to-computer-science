#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

// This program computes the Coleman-Liau index of text.

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Gets text as an input from the user.
    string text = get_string("Text: ");
    // Average number of letters per 100 words in the text.
    float L = ((float)count_letters(text) / count_words(text)) * 100;
    // Average number of sentences per 100 words in the text.
    float S = ((float)count_sentences(text) / count_words(text)) * 100;
    // Formula.
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(grade));
    }
}
// Check wheter a character is a symbol (punctuation + symbol) in the ASCII table.
bool issymbol(char character)
{
    for (int i = 33; i <= 47; i++)
    {
        if ((int)character == i)
        {
            return true;
        }
    }
    for (int i = 58; i <= 64; i++)
    {
        if ((int)character == i)
        {
            return true;
        }
    }
    for (int i = 91; i <= 96; i++)
    {
        if ((int)character == i)
        {
            return true;
        }
    }
    for (int i = 123; i <= 126; i++)
    {
        if ((int)character == i)
        {
            return true;
        }
    }
    return false;
}
// Counts the letters in given text.
int count_letters(string text)
{
    int letters = 0;
    // Iterates through the text.
    for (int i = 0; i < strlen(text); i++)
    {
        // if the current character is a letter the letters counter will increase.
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}
// Counts the words in given text.
int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // First detects if the current character is alphabetic.
        if (isalpha(text[i]))
        {
            // Then checks if the next character is either a space or the end of the string.
            // If it is, increases the words counter.
            if (isspace(text[i + 1]) || text[i + 1] == '\0')
            {
                words++;
            }
        }
        // Same idea for symbols.
        // Any words with dashes or simillar still counts as 1 word.
        else if (issymbol(text[i]))
        {
            if (isspace(text[i + 1]) || text[i + 1] == '\0')
            {
                words++;
            }
        }

    }
    return words;
}
// Counts the sentences in given text.
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Defines that if one of these punctuation characters is found, one sentence ends and the sentences counter increases.
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
