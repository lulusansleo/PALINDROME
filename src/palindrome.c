/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** palindrome
*/

#include "palindrome.h"

int reverse_number(int nb, int base)
{
    int digit = 0;
    int reverse = 0;

    while (nb > 0) {
        digit = nb % base;
        reverse = (reverse * 10) + digit;
        nb = nb / 10;
    }
    return reverse;
}

int base_addition(int nb, int add, int base)
{
    int res = 0;
    int digit = 0;
    int power = 1;

    while (nb > 0 || add > 0) {
        digit = (nb % base) + (add % base);
        if (digit >= base) {
            res += ((digit - base) * power) * 10;
            digit -= base;
        }
        res += digit * power;
        nb = nb / 10;
        add = add / 10;
        power *= 10;
    }
    return res;
}

int change_from_base(int nb, int base)
{
    int result = 0;
    int power = 1;
    int digit = 0;

    while (nb > 0) {
        digit = nb % base;
        result += digit * power;
        power *= base;
        nb = nb / 10;
    }
    return result;
}

int change_to_base(int nb, int base)
{
    int result = 0;
    int power = 1;

    while (nb > 0) {
        result += (nb % base) * power;
        nb = nb / base;
        power *= 10;
    }
    return result;
}

int palindrome(int nb, int base, it_info_t *info)
{
    int i = 0;
    int reverse = 0;
    int copy = nb;

    if (base < 10)
        nb = change_to_base(nb, base);
    for (i = 0; (reverse = reverse_number(nb, base)) != nb
    && i < info->i_max; i++) {
        if (base < 10)
            nb = base_addition(nb, reverse, base);
        else
            nb = nb + reverse;
        if (nb > __INT_MAX__ || nb < 0)
            return -1;
    }
    if (base < 10)
        nb = change_from_base(nb, base);
    if (i > info->i_min)
        printf("%d leads to %d in %d iterations in base %d\n",copy, nb, i, base);
    return 0;
}
