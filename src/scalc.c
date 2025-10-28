#include "scalc.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>

// handles SIGINT ctrl+c while in main loop
static void catch_sigint(int signal)
{
    usr_signal = signal;
}

void parse_usr_input()
{
    // do shit
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
        printf("%s\n", usr_input);
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
    } while (usr_input == NULL);

    add_history(usr_input);
    return usr_input;
}

void format_prompt(char *prompt)
{
    // write PROMPT_SIZE bytes to prompt string including \0
    snprintf(prompt, PROMPT_SIZE, "%s%s >>>%s ", MODE_STRING[current_mode],
             MODE_COLOR[current_mode], RESET_ATTRIBUTES);
}
