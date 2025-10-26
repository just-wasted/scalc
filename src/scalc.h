#include <stdio.h>
#include <string.h>

#define RESET_ATTRIBUTES "\e[0m"
#define FORGROUND_CYAN "\e[38;5;68m"
#define INPUT_BUFFER_SIZE 50

enum CALC_MODE
{
    CALC,
    CONV
};

static const char *MODE_STRING[] = {"calc", "conv"};

void print_prompt(enum CALC_MODE mode);
void get_input(char *buffer, enum CALC_MODE mode);
