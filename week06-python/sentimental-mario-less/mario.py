# Prints out a half-pyramid of a specified height

from cs50 import get_int


def main():

    # Prompts the user for the height untill a value in the 1-8 range is given
    while True:
        height = get_int("Height: ")
        if height in range(1, 9):
            break

    global initial_height
    initial_height = height

    draw_pyramid(height)


# Draws a pyramid recursivelly
def draw_pyramid(height):
    if height > 0:
        draw_pyramid(height - 1)

        print(" " * (initial_height - height), end="")
        print("#" * height)


if __name__ == "__main__":
    main()
