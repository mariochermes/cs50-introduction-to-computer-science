# Determines whether a provided credit card number is valid according to Luhn’s algorithm

from cs50 import get_int
import re


def main():

    # Define card types through regular expressions
    card_formats = {
        "AMEX": "^3[47][0-9]{13}$",
        "VISA": "^4[0-9]{12,15}$",
        "MASTERCARD": "^5[12345][0-9]{14}$"
    }

    # Gets the card number as an integer bigger than 0
    while True:
        card_number = get_int("Number: ")
        if card_number > 0:
            break

    # Compares the number to the card types in the dictionary
    for type in card_formats.keys():
        test = card_formats[type]
        if re.match(test, str(card_number)):
            card_type = type

    # Prints the card type if valid
    if luhns_algorithm(str(card_number)):
        try:
            print(card_type)
        except NameError:
            print("INVALID")
    else:
        print("INVALID")


# Applies Luhn's Algorithm to check if a credit number is valid
def luhns_algorithm(card_number):
    sum = 0
    # Control variable to only use part of the formula in each other digit, starting with the second-to-last
    other = False
    for i in range(len(card_number) - 1, -1, -1):
        current_digit = int(card_number[i])
        if other == True:
            current_digit = current_digit * 2
            if current_digit >= 10:
                current_digit = digit_sum(current_digit)
            other = False
        else:
            other = True

        sum += current_digit

    if sum % 10 == 0:
        return True
    else:
        return False


# Sums the digits of a number
def digit_sum(n):
    sum = 0

    for digit in str(n):
        sum += int(digit)

    return sum


if __name__ == "__main__":
    main()
