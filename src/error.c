/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** error_handling
*/

#include "palindrome.h"

int is_str_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int number_error(char *str)
{
    if (atoi(str) <= 0) {
        dprintf(2, "invalid argument\n");
        return 1;
    }
    return 0;
}

int check_arg(int ac, char **av)
{
    for (int i = 3; av[i]; i++) {
        if ((strcmp(av[i], "-imin") == 0 || strcmp(av[i], "-imax") == 0 ||
        strcmp(av[i], "-b") == 0) && is_str_digit(av[i + 1]))
            i++;
        else {
            dprintf(2, "invalid argument\n");
            return 1;
        }
    }
    return 0;
}
