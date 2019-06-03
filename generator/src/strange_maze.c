/*
** EPITECH PROJECT, 2019
** generator
** File description:
** strange_maze
*/

#include "generator.h"

int strange_maze(char **maze, coord_t size, pile_t *pile)
{
    if (size.height == 1) {
        for (int i = 0; maze[0][i] != '\0'; i++)
            maze[0][i] = '*';
        return (display_maze(maze, pile));
    } else if (size.width == 1) {
        for (int i = 0; maze[i] != NULL; i++)
            maze[i][0] = '*';
        return (display_maze(maze, pile));
    }
    return (ERROR);
}