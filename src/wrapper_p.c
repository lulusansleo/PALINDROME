/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** wrapper -p
*/

#include "palindrome.h"

static int check_palindrome(long int nb, long int base)
{
    long int rev = 0;

    nb = change_to_base(nb, base);
    rev = reverse_number(nb, base);

    if (nb != rev)
        return 1;

    return 0;
}

int palindrome_p_wrapper(int ac, char **av)
{
    it_info_t *info = malloc(sizeof (it_info_t));
    long int base = 10;

    info->i_max = 100;
    info->i_min = 0;
    if (ac > 3)
        base = get_params(info, av);
    if (check_values(base, info) || check_palindrome(atoi(av[2]), base)) {
        dprintf(2, "invalid argument\n");
        free(info);
        return 1;
    };
    palindrome_p(atoi(av[2]), base, info);
    free(info);
    return 0;
}
