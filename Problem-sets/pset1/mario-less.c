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

void print_whitespace(int amount) 
{
	while (amount > 0) 
	{
		printf(" ");
		amount = amount - 1;
	}
}

void print_steps(int amount) 
{
	while (amount > 0) 
	{
		printf("#");
		amount = amount - 1;
	}
	printf("\n");
}

int main(void) 
{
	int height = 0;
  while (1) 
	{
		height = get_int("Height: ");
		if (height >= 1 && height <= 8) 
		{
			break;
		} 
		else 
		{
			continue; 
		}
	}

	int steps = 0; 
	while (height >= 0) 
	{
		print_whitespace(8 - steps);
		print_steps(steps);
		steps = steps + 1;
		height = height - 1;
	}
  return 0;
}
