#include <stdio.h>

#define RESET_ATTRIBUTES "\e[0m"
#define INPUT_BUFFER_SIZE 50
#define COMMAND_LEN 4

volatile int usr_signal = 0;
// bytes in prompt string to fit necessary data
static const size_t PROMPT_SIZE = 50;

typedef enum
{
    CALC,
    PROG,
    CONV
} MODE;

MODE current_mode;
// define string to print in prompt for each mode
static const char *MODE_STRING[] = {"calc", "prog", "conv"};

// define color to use in prompt for each mode
static const char *MODE_COLOR[] = {
    "\e[38;5;202m", // foreground orange for calc mode
    "\e[38;5;37m", // foreground cyan for prog mode
    "\e[38;5;68m" // foreground blue for conv mode
};

// formats the string representing the prompt for readline
void format_prompt(char *prompt);

// uses readline to print a prompt and get an input string from the user
char *get_input(char *prompt);

// parses the user input into tokens and decides how to handle it
void parse_usr_input(char *str);

// checks if the string is a valid command and acts accordingly
void parse_command(char *str);
