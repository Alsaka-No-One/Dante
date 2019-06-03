/*
** EPITECH PROJECT, 2019
** generator
** File description:
** find_maze
*/

#include "generator.h"

static char **create_maze(coord_t size)
{
    char **maze = NULL;

    if ((maze = malloc(sizeof(char *) * (size.height + 1))) == NULL)
        return (NULL);
    for (int i = 0; i < size.height; i++)
        if ((maze[i] = malloc(sizeof(char) * (size.width + 1))) == NULL)
            return (NULL);
    return (maze);
}

static void fill_maze(char ***maze, coord_t size)
{
    int i = 0;

    for (int j = 0; i < size.height; j++) {
        if (i == size.height - 1 && j == size.width) {
            (*maze)[i][j] = '\0';
            break;
        }
        if (j == size.width) {
            (*maze)[i][j] = '\0';
            i += 1;
            j = 0;
        }
        (*maze)[i][j] = 'X';
    }
    (*maze)[size.height] = NULL;
}

int find_maze(char **argv)
{
    char **maze = NULL;
    coord_t size;
    pile_t *pile;

    pile = malloc(sizeof(pile_t) * (atoi(argv[1]) * atoi(argv[2])));
    if (pile == NULL)
        return (ERROR);
    size.width = atoi(argv[1]);
    size.height = atoi(argv[2]);
    maze = create_maze(size);
    if (maze == NULL)
        return (ERROR);
    fill_maze(&maze, size);
    if (argv[3])
        return (perfect_maze(maze, size, pile));
    return (imperfect_maze(maze, size, pile));
}