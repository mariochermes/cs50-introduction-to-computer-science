# Computes the approximate grade level needed to comprehend some text

from cs50 import get_string
import re


def main():

    text = get_string("Text: ").lower()

    # Average number of letters per 100 words in the text.
    L = count_letters(text) / count_words(text) * 100
    # Average number of sentences per 100 words in the text.
    S = count_sentences(text) / count_words(text) * 100
    # Formula.
    grade = 0.0588 * L - 0.296 * S - 15.8
    grade = round(grade)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade: {int(grade)}")


# Counts the number of letters in text
def count_letters(text):
    return len([l for l in text if l.isalpha()])


# Counts the number of words in text
def count_words(text):
    return len(text.split(" "))


# Counts the number of sentences in text
def count_sentences(text):
    return len(re.split(r"[.!?]+", text)) - 1


if __name__ == "__main__":
    main()
