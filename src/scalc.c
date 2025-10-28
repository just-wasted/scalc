#include "scalc.h"
#include <ctype.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// handles SIGINT ctrl+c while in main loop
static void catch_sigint(int signal)
{
    usr_signal = signal;
}

int main(void)
{
    signal(SIGINT, catch_sigint);
    current_mode = CALC;

    // change readline's getc function pointer to avoid readline blocking
    // if user sends SIGINT
    rl_getc_function = getc;

    char *prompt = malloc(sizeof(char) * PROMPT_SIZE);

    while (usr_signal != SIGINT)
    {
        char *usr_input = get_input(prompt);
        if (usr_signal == SIGINT)
        {
            break;
        }
        parse_usr_input(usr_input);
    }

    free(prompt);
    clear_history();
    printf("User Exit\n");
    return EXIT_SUCCESS;
}

char *get_input(char *prompt)
{
    char *usr_input = NULL;
    format_prompt(prompt);

    do
    {
        if (usr_signal == SIGINT)
        {
            break;
        }
        usr_input = readline(prompt);
    } while (usr_input == NULL ||
             *usr_input == '\0'); // avoid adding empty strings to history

    add_history(usr_input);
    return usr_input;
}

void format_prompt(char *prompt)
{
    // write PROMPT_SIZE bytes to prompt string including \0
    snprintf(prompt, PROMPT_SIZE, "%s%s >>>%s ", MODE_STRING[current_mode],
             MODE_COLOR[current_mode], RESET_ATTRIBUTES);
}

void parse_usr_input(char *str)
{
    char *token = NULL;
    token = strtok(str, " +-/=^%");

    bool flag_parse_for_cmd = true;

    if (strlen(token) == COMMAND_LEN)
    {
        for (int i = 0; i < COMMAND_LEN; i++)
        {
            if (!isalpha(str[i]))
            {
                flag_parse_for_cmd = false;
            }
        }
        if (flag_parse_for_cmd)
        {
            parse_command(token);
        }
    }
}

void parse_command(char *str)
{
    printf("Unknown Command: %s\n", str);
    printf("Type 'help' to display help text.\n");
}
