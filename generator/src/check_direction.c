/*
** EPITECH PROJECT, 2019
** generator
** File description:
** check_direction
*/

#include "generator.h"

int check_direction(char **maze, int x, int y)
{
    if (x - 2 >= 0 && maze[x - 2][y] != '*'
        && maze[x - 1][y] != '*')
        return (SUCCESS);
    if (maze[x][y + 1] != '\0'
        && maze[x][y + 2] != '\0'
        && maze[x][y + 1] != '*'
        && maze[x][y + 2] != '*')
        return (SUCCESS);
    if (maze[x + 2] != NULL && maze[x + 1] != NULL
        && maze[x + 2][y] != '*'
        && maze[x + 1][y] != '*')
        return (SUCCESS);
    if (y - 2 >= 0 && maze[x][y - 2] != '*'
        && maze[x][y - 1] != '*')
        return (SUCCESS);
    return (ERROR);
}

void check_direction_pile(char **maze, coord_t *size, pile_t *pile,
    int *pile_index)
{
    *pile_index -= 1;
    while (check_direction(maze, pile[*pile_index].x,
            pile[*pile_index].y) == ERROR
            && *pile_index > 0)
        *pile_index -= 1;
    if (*pile_index > 0) {
        size->x = pile[*pile_index].x;
        size->y = pile[*pile_index].y;
    }
}