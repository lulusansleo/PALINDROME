/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** requirement
*/

int my_factrec_synthesis(int nb)
{
    if (nb == 0 || nb == 1)
        return 1;
    if (nb < 0 || nb > 12)
        return 0;
    return my_factrec_synthesis(nb - 1) * nb;
}

int my_squareroot_synthesis(int nb)
{
    int i = 1;

    if (nb == 0)
        return 0;
    if (nb < 0)
        return -1;
    while (i * i != nb) {
        if ((i * i) > nb)
            return -1;
        i++;
    }
    return i;
}
