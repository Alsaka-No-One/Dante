/*
** EPITECH PROJECT, 2019
** generator
** File description:
** create_maze
*/

#include "generator.h"

int start(coord_t *size)
{
    if (size->width != 1 && size->height != 1) {
        size->x = 0;
        size->y = 0;
        size->status = 1;
        return (SUCCESS);
    }
    return (ERROR);
}

void fill_pile(pile_t *pile, int *pile_index, coord_t *path)
{
    pile[*pile_index].x = path->x;
    pile[*pile_index].y = path->y;
    *pile_index += 1;
}

int perfect_maze(char **maze, coord_t size, pile_t *pile)
{
    int pile_index = 0;

    if (start(&size) != SUCCESS)
        return (strange_maze(maze, size, pile));
    fill_pile(pile, &pile_index, &size);
    maze[size.x][size.y] = '*';
    do {
        algo_perfect(maze, pile, &size, &pile_index);
        check_direction_pile(maze, &size, pile, &pile_index);
    } while (pile_index > 0);
    maze[size.height - 1][size.width - 1] = '*';
    maze[size.height - 1][size.width - 2] = '*';
    return (display_maze(maze, pile));
}