/*
** EPITECH PROJECT, 2019
** generator
** File description:
** imperfect_maze
*/

#include "generator.h"

void draw_imperfect(char **maze, int x)
{
    int cols = x / 2;

    for (int i = 0; i != x / 10; i++) {
        for (int j = 0; maze[j] != NULL; j++)
            maze[j][cols] = '*';
        cols += 4;
    }
}

static void make_imperfect(char **maze, coord_t *size)
{
    int cols = 0;

    if (size->width >= 10) {
        draw_imperfect(maze, size->width);
        return;
    }
    srand(time(NULL));
    cols = rand() % (size->width - 1);
    if (cols == 0)
        cols++;
    for (int i = 0; maze[i] != NULL; i++)
        maze[i][cols] = '*';
}

int imperfect_maze(char **maze, coord_t size, pile_t *pile)
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
    make_imperfect(maze, &size);
    return (display_maze(maze, pile));
}