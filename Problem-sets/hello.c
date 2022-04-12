#include <stdio.h>
#include <stdlib.h>

typedef char *string; 

char * get_string(const char *prompt) 
{
		const int buffer_size = 256;
		printf("%s", prompt);
		char input[buffer_size];
		fgets(&input, buffer_size, stdin);
		fflush(stdin); 
		return input;
}

int main(void) {
  string name = get_string("What's your name? ");
	printf("Hello, %s\n", name);
  return 0;
}
