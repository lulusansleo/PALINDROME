/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** error_handling
*/

#include "palindrome.h"

long int is_str_digit(char *str)
{
    for (long int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

long int number_error(char *str)
{
    if (atoi(str) <= 0) {
        dprintf(2, "invalid argument\n");
        return 1;
    }
    return 0;
}

long int check_arg(long int ac, char **av)
{
    for (long int i = 3; av[i]; i++) {
        if ((strcmp(av[i], "-imin") == 0 || strcmp(av[i], "-imax") == 0 ||
        strcmp(av[i], "-b") == 0) && av[i + 1] && is_str_digit(av[i + 1]))
            i++;
        else {
            dprintf(2, "invalid argument\n");
            return 1;
        }
    }
    return 0;
}
