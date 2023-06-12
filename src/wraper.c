/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** wraper
*/

#include"palindrome.h"

void palindrome_wrapper(int ac, char **av)
{
    if (strcmp("-n", av[1]) == 0)
        palindrome(atoi(av[2]), 10);
}
