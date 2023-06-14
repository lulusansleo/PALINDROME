/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** unit_tests
*/

#include "palindrome.h"
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/redirect.h>


void redirect_err(void)
{
    cr_redirect_stderr();
}

void redirect_out(void)
{
    cr_redirect_stdout();
}

Test(palindrome_tests, palindrome_p_only, .init=redirect_err)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    char *arr[3] = {"./palindrome", "-p", "12"};
    int ac = 3;

    for_test->i_max = 100;
    for_test->i_min = 0;

    palindrome_p_wrapper(ac, arr);
    cr_assert_stderr_eq_str("invalid argument\n");
    free(for_test);
}

Test(palindrome_tests, palindrome_p_all, .init=redirect_out)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long nb = 111111;
    long base = 10;
    for_test->i_max = 100;
    for_test->i_min = 2;

    cr_assert_eq(palindrome_p(nb, base, for_test), 0);
    free(for_test);
}

Test(palindrome_tests, palindrome_p_al, .init=redirect_out)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long nb = 65;
    long base = 2;
    for_test->i_max = 100;
    for_test->i_min = 2;

    cr_assert_eq(palindrome_p(nb, base, for_test), 0);
    free(for_test);
}

Test(palindrome_tests, palindrome_all, .init=redirect_out)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long nb = 657;
    long base = 10;
    for_test->i_max = 100;
    for_test->i_min = 2;

    cr_assert_eq(palindrome(nb, base, for_test), 0);
    free(for_test);
}

Test(palindrome_tests, palindrome_ll, .init=redirect_out)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long nb = 657;
    long base = 10;
    for_test->i_max = 0;
    for_test->i_min = 0;

    cr_assert_eq(palindrome(nb, base, for_test), 1);
    free(for_test);
}

Test(palindrome_tests, palindrome_alll, .init=redirect_out)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long nb = 65;
    long base = 2;
    for_test->i_max = 100;
    for_test->i_min = 2;

    cr_assert_eq(palindrome(nb, base, for_test), 0);
    free(for_test);
}

Test(palindrome_tests, palindrome_allll, .init=redirect_out)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long nb = -1000000;
    long base = 2;
    for_test->i_max = 100;
    for_test->i_min = 2;

    cr_assert_eq(palindrome(nb, base, for_test), 0);
    free(for_test);
}

Test(palindrome_tests, palindrome_p_all_base_two, .init=redirect_out)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long nb = 65;
    long base = 2;
    for_test->i_max = 100;
    for_test->i_min = 0;

    cr_assert_eq(palindrome_p(nb, base, for_test), 0);
    free(for_test);
}

Test(palindrome_tests, palindrome_p_only_wrong_arg, .init=redirect_err)
{
    char *arr[3] = {"./palindrome", "-p", "a"};
    int ac = 3;

    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(palindrome_tests, palindrome_p_only_good, .init=redirect_out)
{
    char *arr[3] = {"./palindrome", "-p", "1"};
    int ac = 3;

    cr_assert_eq(palindrome_p_wrapper(ac, arr), 0);
}

Test(palindrome_tests, palindrome_p_check_balue, .init=redirect_err)
{
    char *arr[6] = {"./palindrome", "-p", "13", "-b", "-10"};
    int ac = 5;

    cr_assert_eq(palindrome_p_wrapper(ac, arr), 1);
}

Test(palindrome_tests, palindrome_p_check_value, .init=redirect_out)
{
    char *arr[6] = {"./palindrome", "-p", "65", "-b", "2"};
    int ac = 5;

    cr_assert_eq(palindrome_p_wrapper(ac, arr), 0);
}

Test(palindrome_tests, palindrome_p_check_values, .init=redirect_out)
{
    char *arr[6] = {"./palindrome", "-p", "565", "-b", "10"};
    int ac = 5;

    cr_assert_eq(palindrome_p_wrapper(ac, arr), 0);
}

Test(palindrome_tests, palindrome_check_value, .init=redirect_out)
{
    char *arr[6] = {"./palindrome", "-n", "13", "-imax", "0"};
    int ac = 5;

    cr_assert_eq(palindrome_wrapper(ac, arr), 0);
}

Test(palindrome_tests, palindrome_check_value_bis, .init=redirect_err)
{
    char *arr[6] = {"./palindrome", "-n", "13", "-imax", "-10"};
    int ac = 5;

    cr_assert_eq(palindrome_wrapper(ac, arr), 1);
}

Test(palindrome_tests, palindrome_check_value_ter, .init=redirect_out)
{
    char *arr[6] = {"./palindrome", "-n", "13", "-imax", "-10"};
    int ac = 3;

    cr_assert_eq(palindrome_wrapper(ac, arr), 0);
}


Test(unit_testss, check_the_values_right_base)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long int base = 10;

    for_test->i_max = 100;
    for_test->i_min = 0;

    cr_assert_eq(check_values(base, for_test), 0);
    free(for_test);
}

Test(unit_testss, check_the_values_wrong_base, .init=redirect_err)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long int base = -10;

    for_test->i_max = 100;
    for_test->i_min = 0;

    cr_assert_eq(check_values(base, for_test), 1);
    free(for_test);
}

Test(unit_testss, check_the_values_wrong_base_above, .init=redirect_err)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long int base = 12;

    for_test->i_max = 100;
    for_test->i_min = 0;

    cr_assert_eq(check_values(base, for_test), 1);
    free(for_test);
}

Test(unit_testss, check_the_values_imax_imin, .init=redirect_err)
{
    it_info_t *for_test = malloc(sizeof (it_info_t *));
    long int base = 9;

    for_test->i_max = 1;
    for_test->i_min = 10;

    cr_assert_eq(check_values(base, for_test), 1);
    free(for_test);
}

Test(unit_testss, check_str_digit)
{
    cr_assert_eq(is_str_digit("123"), 1);
}

Test(unit_testss, check_str_digit_wrong)
{
    cr_assert_eq(is_str_digit("a"), 0);
}

Test(unit_testss, check_value)
{
    char nb[3] = "12";
    cr_assert_eq(number_error(nb), 0);
}

Test(unit_testss, check_value_error, .init=redirect_err)
{
    char nb[3] = "-1";
    cr_assert_eq(number_error(nb), 1);
}

Test(unit_testss, check_args, .init=redirect_err)
{
    char *arr[7] = {"./palindrome", "-p", "a", "-b", "9", "-imin"};
    int ac = 6;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_no_p_or_n, .init=redirect_err)
{
    char *arr[7] = {"./palindrome", "-o", "10", "-b", "9", "-imin"};
    int ac = 6;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_correct, .init=redirect_out)
{
    char *arr[11] = {"./palindrome", "-n", "12", "-b", "9", "-imin", "0", "-imax", "10"};
    int ac = 10;
    cr_assert_eq(error_handling(ac, arr), 0);
}

Test(unit_testss, check_args_correctsasda, .init=redirect_out)
{
    char *arr[11] = {"./palindrome", "-n", "12", "-b", "-imin", "0", "-imax", "10"};
    int ac = 10;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_no_number_after_flag, .init=redirect_err)
{
    char *arr[11] = {"./palindrome", "-n", "12", "-b", "1", "-imin", "a", "-imax", "10"};
    int ac = 10;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_too_few, .init=redirect_err)
{
    char *arr[11] = {"./palindrome", "-n", "12", "-b", "a", "-imin", "0", "-imax", "10"};
    int ac = 2;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_too_many, .init=redirect_err)
{
    char *arr[11] = {"./palindrome", "-n", "12", "-b", "1", "-imin", "0", "-imax"};
    int ac = 100;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_p_and_n, .init=redirect_err)
{
    char *arr[11] = {"./palindrome", "-n", "12", "-p", "a", "-imin", "-imax", "10"};
    int ac = 10;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_n_and_p, .init=redirect_err)
{
    char *arr[11] = {"./palindrome", "-p", "12", "-n", "a", "-imin", "0", "-imax", "10"};
    int ac = 10;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_args_nothing_after_b, .init=redirect_err)
{
    char *arr[5] = {"./palindrome", "-p", "12", "-b"};
    int ac = 4;
    cr_assert_eq(error_handling(ac, arr), 1);
}

Test(unit_testss, check_reverse_base)
{
    cr_assert_eq(reverse_number(12, 10), 21);
}

Test(unit_testss, addition_longer_nb)
{
    cr_assert_eq(base_addition(12, 8, 10), 20);
}

Test(unit_testss, addition_longer_add)
{
    cr_assert_eq(base_addition(8, 12, 10), 20);
}

Test(unit_testss, addition_longer_sum)
{
    cr_assert_eq(base_addition(99, 2, 10), 101);
}

Test(unit_testss, change_base_ten)
{
    cr_assert_eq(change_from_base((long) 10, (long) 10), 10);
}

Test(unit_testss, change_base_nine)
{
    cr_assert_eq(change_from_base((long) 11, (long) 9), (long) 10);
}

Test(unit_testss, change_to_base_ten)
{
    cr_assert_eq(change_to_base((long) 10, (long) 10), 10);
}

Test(unit_testss, change_to_base_nine)
{
    cr_assert_eq(change_to_base((long) 10, (long) 9), 11);
}

Test(unit_testss, get_params)
{
    char *arr[11] = {"./palindrome", "-n", "12", "-b", "9", "-imin", "0", "-imax", "10"};

    it_info_t *for_test = malloc(sizeof (it_info_t *));
    cr_assert_eq(get_params(for_test, arr), 9);
}
