/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** main
*/

#include "palindrome.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_usage(1);
        return 0;
    }
    if (error_handling(ac, av))
        return 84;
    if (strcmp(av[1], "-n") == 0)
        if (palindrome_wrapper(ac, av))
            return 84;
    if (strcmp(av[1], "-p") == 0)
        if (palindrome_p_wrapper(ac, av))
            return 84;
    return 0;
}
