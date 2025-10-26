#include "scalc.h"

int main(void)
{
    enum CALC_MODE cur_mode = CALC;

    char input_str[INPUT_BUFFER_SIZE];
    get_input(input_str, cur_mode);
    printf("%s\n", input_str);
    return 0;
}

void get_input(char *buffer, enum CALC_MODE mode)
{
    // int valid_input = 0;
    print_prompt(mode);

    while (fgets(buffer, sizeof(char) * INPUT_BUFFER_SIZE, stdin) == NULL)
    {
        printf("Input Error!\n");
        print_prompt(mode);
        printf("%ld\n", strlen(buffer));
    }
}

void print_prompt(enum CALC_MODE mode)
{
    printf("%s ", MODE_STRING[mode]);
    printf("%s", FORGROUND_CYAN);
    printf(">>> ");
    printf("%s", RESET_ATTRIBUTES);
}
