/*
** EPITECH PROJECT, 2019
** generator
** File description:
** display_free_tab
*/

#include "generator.h"

int display_maze(char **maze, pile_t *pile)
{
    int i = 0;

    while (maze[i + 1] != NULL) {
        write(1, maze[i], strlen(maze[i]));
        write(1, "\n", 1);
        free(maze[i]);
        i++;
    }
    write(1, maze[i], strlen(maze[i]));
    free(maze[i]);
    free(maze);
    free(pile);
    return (SUCCESS);
}