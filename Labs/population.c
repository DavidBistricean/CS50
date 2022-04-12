#include <stdio.h>
#include <stdlib.h>

//Couldn't get cs50.h to work on replit.com
//so I made my own get_input() function
int get_int(const char *prompt) 
{
		const int buffer_size = 256;
		printf("%s", prompt);
		char input[buffer_size];
		fgets(&input, buffer_size, stdin);
		fflush(stdin); 
		return atoi(input);
}

int main(void)
{
    // TODO: Prompt for start size
		int start_size = 0;
		int end_size = 0;
		while (1) {
			start_size = get_int("Start size: ");
			if (start_size < 9) {
				continue;
			}
			else {
				break; 
			}
		}
    // TODO: Prompt for end size
		while (1) {
			end_size = get_int("End size: ");
			if (end_size < start_size) {
				continue;
			}
			else {
				break; 
			}
		}
    // TODO: Calculate number of years until we reach threshold
		int years = 0; 
		int current_pop = start_size; 
		while (current_pop < end_size) {
			int increase = current_pop / 3;
			int decrease = current_pop / 4; 
			current_pop = current_pop + increase;
			current_pop = current_pop - decrease;
			years = years + 1;
		}
    // TODO: Print number of years
		printf("Years: %d\n", years);
}
