/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** wraper
*/

#include"palindrome.h"

void get_params(it_info_t *info, char **av)
{
    for (int i = 0; av[i]; i++) {
        if (strcmp("-imin", av[i]) == 0) {
            info->i_min = atoi(av[i + 1]);
        }
        if (strcmp("-imax", av[i]) == 0) {
            info->i_max = atoi(av[i + 1]);
        }
    }
}

void palindrome_wrapper(int ac, char **av)
{
    it_info_t *info = malloc(sizeof (it_info_t));

    info->i_max = 100;
    info->i_min = 0;
    if (ac > 3)
        get_params(info, av);

    if (strcmp("-n", av[1]) == 0)
        if (palindrome(atoi(av[2]), 10, info))
            printf("no solution\n");

    free(info);
}
