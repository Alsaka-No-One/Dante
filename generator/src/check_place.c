/*
** EPITECH PROJECT, 2019
** generator
** File description:
** check_map
*/

#include "generator.h"

int check_up(char **maze, coord_t *size, int x, int y)
{
    if (x >= 0 && maze[x][y] != '*' && maze[x + 1][y]) {
        maze[x][y] = '*';
        maze[x + 1][y] = '*';
        size->x = x;
        size->y = y;
        return (SUCCESS);
    }
    return (ERROR);
}

int check_right(char **maze, coord_t *size, int x, int y)
{
    if (maze[x][y] != '\0' && maze[x][y - 1] != '\0'
        && maze[x][y - 1] != '*' && maze[x][y] != '*') {
        maze[x][y] = '*';
        maze[x][y - 1] = '*';
        size->x = x;
        size->y = y;
        return (SUCCESS);
    }
    return (ERROR);
}

int check_down(char **maze, coord_t *size, int x, int y)
{
    if (maze[x] != NULL && maze[x - 1] != NULL
        && maze[x][y] != '*' && maze[x - 1][y] != '*') {
        maze[x][y] = '*';
        maze[x - 1][y] = '*';
        size->x = x;
        size->y = y;
        return (SUCCESS);
    }
    return (ERROR);
}

int check_left(char **maze, coord_t *size, int x, int y)
{
    if (y >= 0 && maze[x][y] != '*' && maze[x][y + 1] != '*') {
        maze[x][y] = '*';
        maze[x][y + 1] = '*';
        size->x = x;
        size->y = y;
        return (SUCCESS);
    }
    return (ERROR);
}