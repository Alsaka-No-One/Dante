/*
** EPITECH PROJECT, 2019
** solver
** File description:
** unit_test_one
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "generator.h"

Test(return_value_perfect, test_return_value_perfect)
{
    char *arg[] = {"./generator", "100", "100", "perfect"};

    cr_assert_eq(check_input(4, arg), 0);
}

Test(return_value_imperfect, test_return_value_imperfect)
{
    char *arg[] = {"./generator", "100", "100"};

    cr_assert_eq(check_input(3, arg), 0);
}

Test(return_value_imperfect_small, test_return_value_imperfect_small)
{
    char *arg[] = {"./generator", "2", "2"};

    cr_assert_eq(check_input(3, arg), 0);
}

Test(error_input, test_rerror_input)
{
    char *arg[] = {"./generator", "2o", "2"};

    cr_assert_eq(check_input(3, arg), 84);
}

Test(error_input_two, test_rerror_input_two)
{
    char *arg[] = {"./generator", "1", "2", "perf"};

    cr_assert_eq(check_input(4, arg), 84);
}