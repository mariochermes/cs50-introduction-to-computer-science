# Prints out a pyramid of a specified height

from cs50 import get_int


def main():

    # Prompts the user for the height untill a value in the 1-8 range is given
    while True:
        height = get_int("Height: ")
        if height in range(1, 9):
            break

    # Prints a pyramid with the inputed height
    for i in range(1, height + 1):
        print(" " * (height - i), end="")
        print("#" * i, end="  ")
        print("#" * i)


if __name__ == "__main__":
    main()
