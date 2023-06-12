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
        nb = nb / base;
    }
    return reverse;
}

int base_addition(int nb, int base)
{

}

int change_from_base(int nb, int base)
{

}

int change_to_base(int nb, int base)
{
    int result = 0;

    while (nb > 0) {
        result *= 10;
        result += (nb % base) * 10;
        nb = nb / base;
    }
    return result / 10;
}

int palindrome(int nb, int base)
{
    int i = 0;
    int reverse = 0;

    for (i = 0; (reverse = reverse_number(nb, base)) != nb; i++) {
        nb = nb + reverse;
    }
    printf(" leads to %d in %d iterations\n", nb, i);
    return nb;
}
