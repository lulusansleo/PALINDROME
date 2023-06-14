/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** error_handling
*/

#include "palindrome.h"

int is_str_digit(char *str)
{
    for (long int i = 0; str[i] != '\0'; i++) {
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

int check_arg(char **av)
{
    for (int i = 3; av[i]; i++) {
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

void print_usage(int output)
{
    dprintf(output, "USAGE\n\t./palindrome -n number -p palindrome [-b base]");
    dprintf(output, "[-imin i] [-imax i]\n\nDESCRIPTION\n\t-p n\tinteger to");
    dprintf(output, " be transformed (>=0)\n\t-p pal\tpalindromic number to");
    dprintf(output, " be obtained (incompatible with the -n option) (>=0)\n");
    dprintf(output, "\t\tif defined, all fitting values of n will be output");
    dprintf(output, "\n\t-b base\tbase in which the procedure will be ");
    dprintf(output, "executed (1<b<=10) [def: 10]\n\t-imin i minimum number");
    dprintf(output, " of iterations, included (>=0) [def: 0]\n\t-imax i ");
    dprintf(output, "maximum number of iterations, included (>=0) [def: 100]");
    dprintf(output, "\n");
}

int error_handling(int ac, char **av)
{
    if (ac < 3 || ac > 11) {
        print_usage(2);
        return 1;
    }
    if (strcmp(av[1], "-n") != 0 && strcmp(av[1], "-p") != 0) {
        print_usage(2);
        return 1;
    }
    if (ac > 3)
        if (((strcmp(av[1], "-n") == 0 && strcmp(av[3], "-p") == 0)) ||
        ((strcmp(av[1], "-p") == 0 && strcmp(av[3], "-n") == 0)))
            return 1;
    if (number_error(av[2]))
        return 1;
    if (check_arg(av))
        return 1;
    return 0;
}
