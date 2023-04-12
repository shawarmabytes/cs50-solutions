#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int input;
    do
    {
        input = get_int("Change owed: ");
    }
    while (input < 0);
    return input;
}

int calculate_quarters(int cents)
{
    // also print quarters for confirmation
    int quarters = cents / 25;
    printf("Quarters: %i\n", quarters);
    return quarters;
}

int calculate_dimes(int cents)
{
    // also print dimes for confirmation
    int dimes = cents / 10;
    printf("Dimes: %i\n", dimes);
    return dimes;
}

int calculate_nickels(int cents)
{
    // also print nickels for confirmation
    int nickels = cents / 5;
    printf("Nickels: %i\n", nickels);
    return nickels;
}

int calculate_pennies(int cents)
{
    // also print pennies for confirmation
    int pennies = cents / 1;
    printf("Pennies: %i\n", pennies);
    return pennies;
}
