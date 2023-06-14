/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** palindrome
*/

#include "palindrome.h"

long int reverse_number(long int nb, long int base)
{
    long int digit = 0;
    long int reverse = 0;

    while (nb > 0) {
        reverse *= 10;
        digit = (nb % 10) % (base);
        reverse += digit;
        nb = nb / 10;
    }
    return reverse;
}

long int base_addition(long int nb, long int add, long int base)
{
    long int res = 0;
    long int power = 1;
    long int digit = 0;
    long int rest = 0;

    while (nb > 0 || add > 0 || rest > 0) {
        digit = (nb % 10) + (add % 10) + rest;
        rest = digit / base;
        digit %= base;
        res += digit * power;
        nb /= 10;
        add /= 10;
        power *= 10;
    }

    return res;
}

long int change_from_base(long int nb, long int base)
{
    long int result = 0;
    long int power = 1;
    long int digit = 0;

    if (base == 10)
        return nb;
    while (nb > 0) {
        digit = (nb % 10) % base;
        result += digit * power;
        power *= base;
        nb = nb / 10;
    }
    return result;
}

long int change_to_base(long int nb, long int base)
{
    long int result = 0;
    long int power = 1;

    if (base == 10)
        return nb;
    while (nb > 0) {
        result += (nb % base) * power;
        nb = nb / base;
        power *= 10;
    }
    return result;
}

long int palindrome(long int nb, long int base, it_info_t *info)
{
    long int i = 0;
    long int reverse = 0;
    long int copy = nb;
    nb = change_to_base(nb, base);
    for (i = 0; i < info->i_min; i++) {
        reverse = reverse_number(nb, base);
        nb = (base < 10) ? base_addition(nb, reverse, base) : nb + reverse;
    }
    for (; (reverse = reverse_number(nb, base)) != nb; i++) {
        nb = (base < 10) ? base_addition(nb, reverse, base) : nb + reverse;
        if (nb > __LONG_MAX__ || nb < 0 || i >= info->i_max) {
            return 1;
        }
    }
    nb = change_from_base(nb, base);
    printf("%ld leads to %ld in %ld iteration(s) in base %ld\n",
    copy, nb, i, base);
    return 0;
}
