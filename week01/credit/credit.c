#include <cs50.h>
#include <stdio.h>

// Functions are explained at the end.
long power(int base, unsigned int exp);
int digitSum(int num);

int main(void)
{
    // Stores the number on a long due to it's size not fitting into an int.
    long number = get_long("Input your credit card number to see if it's valid or it's type: ");
    // Length of the inserted number, checksum, current digit being operated.
    int length = 0, sum = 0, digit = 0;
    // other is a control variable that makes so only the other digit starting with the number’s second-to-last digit undergo all the algorithm's operations. If other is odd, the digit will just be added to the checksum, if it's even it will be multiplied by two, get it's own digits summed up in case it's higher than 10, and then be added to the checksum.
    int other = 1;
    // This loop takes out one decimal case at the time from the number untill it's 0(or close enough), exposing it's last decimal case. This way I can work with every digit as the remainder when divided by 10 will always be a one decimal case number.
    for (long num = number; num != 0; length++, other++, num /= 10)
    {
        // Operations made with every other digit starting from the second last.
        if (other % 2 == 0)
        {
            digit = (num % 10) * 2;
            if (digit >= 10)
            {
                sum += digitSum(digit);
            }
            else
            {
                sum += digit;
            }
        }
        // Operations made with every other digit starting from the last.
        else
        {
            digit = (num % 10);
            sum += digit;
        }
    }
    // I am able to get the first two digits by dividing the number by 10^length-2.
    long first_digits = number / power(10, length - 2);
    // Verifys if the checksum is valid.
    if (sum % 10 == 0)
    {
        if (first_digits == 34 || first_digits == 37)
        {
            if (length == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (first_digits == 51 || first_digits == 52 || first_digits == 53 || first_digits == 54 || first_digits == 55)
        {
            if (length == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (first_digits / 10 == 4)
        {
            if (length == 13 || length == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
// Function to calculate exponentials.
long power(int base, unsigned int exp)
{
    int i;
    long result = 1;
    for (i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}
// Function to get the sum of digits in a number.
int digitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        sum = sum + digit;
        num /= 10;
    }
    return sum;
}