#include <stdio.h>
#include <stdlib.h>

int get_int(const char *prompt) 
{
		const int buffer_size = 256;
		printf("%s", prompt);
		char input[buffer_size];
		fgets(&input, buffer_size, stdin);
		fflush(stdin); 
		return atoi(input);
}

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
		int cents = 0;
    do 
		{
			cents = get_int("Change due: ");
			if (cents < 1) 
			{
				continue;	
			}
			else 
			{
				return cents;
			}
		} 
		while (1); 
}

int calculate_quarters(int cents)
{
		int iter = 0;
		while (cents >= 25) 
		{
    	cents = cents - 25;
			iter = iter + 1; 
		}
		return iter;
}

int calculate_dimes(int cents)
{
    int iter = 0;
		while (cents >= 10) 
		{
    	cents = cents - 10;
			iter = iter + 1; 
		}
		return iter;
}

int calculate_nickels(int cents)
{
    int iter = 0;
		while (cents >= 5) 
		{
    	cents = cents - 5;
			iter = iter + 1; 
		}
		return iter;
}

int calculate_pennies(int cents)
{
    int iter = 0;
		while (cents >= 1) 
		{
    	cents = cents - 1;
			iter = iter + 1; 
		}
		return iter;
}
