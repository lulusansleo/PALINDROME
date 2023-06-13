/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** wraper
*/

#include"palindrome.h"

long int get_params(it_info_t *info, char **av)
{
    long int base = 10;
    for (long int i = 0; av[i]; i++) {
        if (strcmp("-imin", av[i]) == 0) {
            info->i_min = atoi(av[i + 1]);
        }
        if (strcmp("-imax", av[i]) == 0) {
            info->i_max = atoi(av[i + 1]);
        }
        if (strcmp("-b", av[i]) == 0) {
            base = atoi(av[i + 1]);
        }
    }
    return base;
}

static int check_values(long int base, it_info_t *info)
{
    if (info->i_min > info->i_max || base > 9 || base < 1) {
        return 1;
    }
    return 0;
}

int palindrome_wrapper(long int ac, char **av)
{
    it_info_t *info = malloc(sizeof (it_info_t));
    long int base = 10;

    info->i_max = 100;
    info->i_min = 0;
    if (ac > 3)
        base = get_params(info, av);
    if (check_values(base, info)) {
        dprintf(2, "invalid argument\n");
        free(info);
        return 1;
    };
    if (strcmp("-n", av[1]) == 0)
        if (palindrome(atoi(av[2]), base, info))
            printf("no solution\n");

    free(info);
    return 0;
}
