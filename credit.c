#include <cs50.h>
#include <stdio.h>

int main(void)
{
    bool AMEX = false;
    bool MASTERCARD = false;
    bool VISA = false;
    int sum = 0;
    int sum2 = 0;
    bool eo = false;
    int firstdigit = 0;
    int seconddigit = 0;
    long threshhold = 3999999999999;
    long max = 5599999999999999;
    long num = 0;
    int count= 0; //number of digits in a card number
    do
    {
        num = get_long("Card Number: ");
        if ((num < threshhold) || (num > max))
        {
            printf("not a card number\n");
        }
    }
    while (num < threshhold);

    while (num > 0)
    {
        int digit = num % 10;
        if (eo == true)
        {
            if ( digit > 4)
            {
                digit = digit * 2;
                int digit1 = digit / 10;
                int digit2 = digit % 10;
                sum = sum + digit1 + digit2;
                eo = false;
                firstdigit = digit;
              //  printf("firstdigit: %i\n", firstdigit);
            }
            else
            {
                digit = digit * 2;
                sum = sum + digit;
                eo = false;
                firstdigit = digit;
            }
        }
        else
        {
            sum2 = sum2 + digit;
            eo = true;
            seconddigit = digit;
        }
        num /= 10;
        count++;
    }

    if(count % 2 == 0) //even number of digits
    {
        firstdigit = firstdigit / 2;
        if(firstdigit == 4) //VISA cards start with a 4
        {
            VISA = true;
        }
        if(firstdigit == 5 && (seconddigit > 0 && seconddigit < 6)) //MASTERCARD cards start with 51-55
        {
            MASTERCARD = true;
        }
       // printf("even: the 2nd digit is %i and the 1st digit is %i\n", seconddigit, firstdigit / 2);
    }
    else //odd number of digits
    {
        firstdigit = firstdigit / 2;
        if(seconddigit == 4) //VISA cards start with a 4
        {
            VISA = true;
        }
        if(firstdigit == 7 && seconddigit == 3) //AMEX cards start with 34 or 37
        {
            AMEX = true;
        }
        if(firstdigit == 4 && seconddigit == 3)
        {
            AMEX = true;
        }
        //printf("odd: the 2nd digit is %i and the 1st digit is %i\n", firstdigit / 2, seconddigit);
    }
    sum = sum + sum2;
    if(sum % 10 == 0) // if Luhn's algorithm says the card is valid this will display which type of card it is
    {
        if(AMEX == true)
        {
            printf("AMEX\n");
        }
        if(MASTERCARD == true)
        {
            printf("MASTERCARD\n");
        }
        if(VISA == true)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    //printf("sum is %i and sum2 is %i\n", sum);
}