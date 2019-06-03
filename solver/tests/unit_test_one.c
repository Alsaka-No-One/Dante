/*
** EPITECH PROJECT, 2019
** solver
** File description:
** unit_test_one
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "solver.h"

char **initialize_maze_test(void)
{
    char **maze = malloc(sizeof(char *) * 9);
    char *test[] = {"*X******", "***XX*X*", "*XXX**X*",
                    "*X*XXXXX", "********", "*XXXX*X*",
                    "****X*XX", "*XXXX***"};

    if (maze == NULL)
        return (NULL);
    for (int i = 0; i < 9; i++) {
        maze[i] = malloc(sizeof(char) * 9);
        if (maze[i] == NULL)
            return (NULL);
        for (int j = 0; test[i][j] != '\0'; j++)
            maze[i][j] = test[i][j];
        maze[8] = '\0';
    }
    maze[8] = NULL;
    return (maze);
}

Test(possiblitity, test_possibility)
{
    char **maze = initialize_maze_test();

    if (maze == NULL)
        return;
    maze_or_not(maze);
}

Test(no_possiblitity, test_no_possibility)
{
    char **maze = initialize_maze_test();

    if (maze == NULL)
        return;
    maze[7][6] = 'X';
    maze_or_not(maze);
}

Test(error_charact, test_error_charact)
{
    char **maze = initialize_maze_test();

    if (maze == NULL)
        return;
    maze[7][6] = 'F';
    maze_or_not(maze);
}

Test(error_n_col, test_error_nb_col)
{
    char **maze = initialize_maze_test();

    if (maze == NULL)
        return;
    maze[7][6] = '\0';
    maze_or_not(maze);
}