# Calculates the minimum number of coins required to give a user change

from cs50 import get_float


def main():

    # Asks for the number of cents untill an adequate value is inputed
    while True:
        cents = get_float("Number of cents: ")

        if cents > 0:
            break

    # Gets the number of each type of coin and subtracts it times the value from cents

    quarters = calculate_coins(cents, 0.25)
    cents -= quarters * 0.25

    dimes = calculate_coins(cents, 0.1)
    cents -= dimes * 0.1

    nickels = calculate_coins(cents, 0.05)
    cents -= nickels * 0.05

    pennies = calculate_coins(cents, 0.01)
    cents -= pennies * 0.01

    # Sum each type of coins
    coins = quarters + dimes + nickels + pennies

    print(int(coins))


# Calculates the amount of coins of the inserted value for cents
def calculate_coins(cents, value):
    amount = round(cents, 2) // value
    return amount


if __name__ == "__main__":
    main()
