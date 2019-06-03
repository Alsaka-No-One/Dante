/*
** EPITECH PROJECT, 2019
** solver
** File description:
** print_maze
*/

#include "solver.h"

char delete_charac(char maze)
{
    if (maze == 'O')
        return ('*');
    return (maze);
}

int delete_trace(char **maze, list_t **c_list, list_t **o_list)
{
    free_list(*o_list);
    for (int i = 0; maze[i] != NULL; i++)
        for (int j = 0; maze[i][j] != '\0'; j++)
            maze[i][j] = delete_charac(maze[i][j]);
    return (print_path_in_maze(maze, *c_list));
}

int print_path_in_maze(char **maze, list_t *c_list)
{
    list_t *element = c_list;

    while (c_list != NULL) {
        maze[c_list->pos.x][c_list->pos.y] = 'o';
        c_list = c_list->next;
        free(element);
        element = c_list;
    }
    return (print_maze(maze));
}

int print_maze(char **maze)
{
    int i = 0;

    for (i; maze[i + 1] != NULL; i++)
        printf("%s\n", maze[i]);
    printf("%s", maze[i]);
    free_array(maze);
    return (SUCCESS);
}