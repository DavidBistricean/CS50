#include <stdio.h>
// For the copy of get_long()
#include <stdlib.h>

typedef char * string;

// To replicate how cs50's get_long will reject hyphens
int string_search(char needle, const char haystack[])
{	
		int i = 0; 
		while (i < strlen(haystack))
			{
				if (haystack[i] == needle) 
				{
					return 1; 
				}
				i = i + 1;
			}
	return 0; 
}

/* Basic recreation of cs50's get_long function because
 * I was unable to configure the cs50 header file
 * on replit.com
 */
long get_long(const char *prompt) 
{
		const int buffer_size = 1024;
		printf("%s", prompt);
		char input[buffer_size]; 
		fgets(&input, buffer_size, stdin);
		fflush(stdin); 
		if (string_search('-', input)) 
		{
			return 0; 
		}
		return strtol(input, NULL, 10);
}

string get_card_type(long card) 
{
	string responses[4] = {"AMEX\n", "MASTERCARD\n", "VISA\n", "INVALID\n"};
	if (card >= 4000000000000000 && card < 5000000000000000)
	{
		return responses[2]; 
	}
	else if (card >= 5000000000000000 && card < 6000000000000000) 
	{
		return responses[1];
	}
	else if ((card >= 3700000000000000 && card < 3800000000000000) || (card >= 3400000000000000 && card < 3500000000000000))
	{
		return responses[0];
	}
	else {
		return responses[3]; 
	}
}

int main(void) 
{
	long card = 0; 
  while (1) 
	{
		card = get_long("Number: ");
		if (card < 1) 
		{
			continue; 
		}
		else 
		{
			break; 	
		}
	}
	
}
