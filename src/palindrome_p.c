/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** _p
*/

#include "palindrome.h"

int find_palindrome(long int pal, long int nb, long int base, it_info_t *info)
{
    long int i = 0;
    long int reverse = 0;
    long int copy = nb;
    pal = change_to_base(pal, base);
    nb = change_to_base(nb, base);
    for (i = 0; i < info->i_min; i++) {
        reverse = reverse_number(nb, base);
        nb = (base < 10) ? base_addition(nb, reverse, base) : nb + reverse;
    }
    for (; (reverse = reverse_number(nb, base)) != nb || nb != pal; i++) {
        nb = (base < 10) ? base_addition(nb, reverse, base) : nb + reverse;
        if (i >= info->i_max || nb > pal) {
            return 0;
        }
    }
    nb = change_from_base(nb, base);
    printf("%ld leads to %ld in %ld iteration(s) in base %ld\n",
    copy, nb, i, base);
    return 1;
}

long int palindrome_p(long int nb, long int base, it_info_t *info)
{
    int count = 0;

    for (int i = 1; i <= nb; i++) {
        count += find_palindrome(nb, i, base, info);
    }
    if (count == 0)
        printf("no solution\n");
    return 0;
}
