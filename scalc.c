#include <stdio.h>
#include <string.h>

#define RESET_ATTRIBUTES "\e[0m"
#define FORGROUND_CYAN "\e[38;5;68m"
#define INPUT_BUFFER_SIZE 50

void print_prompt(void);
void get_input(char *buffer);

int main(void)
{
	char input_str[INPUT_BUFFER_SIZE];
	get_input(input_str);
	printf("%s\n", input_str);
	return 0;
}

void get_input(char *buffer)
{
	// int valid_input = 0;
	print_prompt();

	while (fgets(buffer, sizeof(char) * INPUT_BUFFER_SIZE, stdin) == NULL) 
	{
		printf("Input Error!\n");
		print_prompt();
		printf("%ld\n", strlen(buffer));
	}
}

void print_prompt(void)
{
	printf("%s", FORGROUND_CYAN);
	printf(">>> ");
	printf("%s", RESET_ATTRIBUTES);
}
