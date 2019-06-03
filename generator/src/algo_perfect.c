/*
** EPITECH PROJECT, 2019
** generator
** File description:
** algo_perfect
*/

#include "generator.h"

static int check_path2(char **maze, coord_t *size, int direction)
{
    switch (direction) {
    case 3:
        if (check_down(maze, size, (size->x + 2), size->y) == ERROR)
            return (ERROR);
        return (SUCCESS);
    case 4:
        if (check_left(maze, size, size->x, size->y - 2) == ERROR)
            return (ERROR);
        return (SUCCESS);
    default:
        return (ERROR);
    }
}

static int check_path(char **maze, coord_t *size, int direction)
{
    switch (direction) {
    case 1:
        if (check_up(maze, size, (size->x - 2), size->y) == ERROR)
            return (ERROR);
        return (SUCCESS);
    case 2:
        if (check_right(maze, size, size->x, (size->y + 2)) == ERROR)
            return (ERROR);
        return (SUCCESS);
    default:
        return (check_path2(maze, size, direction));
    }
}

static int check_around(char **maze, coord_t *size, int status, int direction)
{
    if (status == 1) {
        (void)direction;
        if (size->x < 0 || size->x >= size->height
            || size->y < 0 || size->y >= size->width)
            return (ERROR);
    }
    if (status == 2) {
        if (check_path(maze, size, direction) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}

static int random_path(char **maze, coord_t *size)
{
    int random = 0;
    int turn = 1;

    if (check_around(maze, size, 1, 0) == ERROR)
        return (ERROR);
    while (turn != SUCCESS) {
        random = rand() % (4 - 1 + 1) + 1;
        turn = check_around(maze, size, 2, random);
    }
    return (SUCCESS);
}

void algo_perfect(char **maze, pile_t *pile, coord_t *size, int *pile_index)
{
    srand(time(NULL));
    while (check_direction(maze, size->x, size->y) != ERROR) {
        random_path(maze, size);
        fill_pile(pile, pile_index, size);
    }
}