/*
** EPITECH PROJECT, 2019
** solver
** File description:
** load_maze
*/

#include "solver.h"

int analyse_line_maze(char **maze, int *i, size_t *len) 
{
    for (int j = 0; maze[*i][j] != '\0'; j++) {
        if (!(maze[*i][j] == 'X' || maze[*i][j] == '*'))
            return (ERROR);
        if (maze[*i + 1] == NULL && ((maze[*i][*len - 1] != '*')
            || (*i + 1 == 1 && *len == 1)))
            return (ERROR);
    }
    return (SUCCESS);
}

int maze_or_not(char **maze)
{
    size_t len = strlen(maze[0]);

    for (int i = 0; maze[i] != NULL; i++)
        if (len != strlen(maze[i]))
            return (error_free_maze(maze, ERROR));
    if (!(maze[0][0] != '\0' && maze[0][0] == '*'))
        return (error_free_maze(maze, SUCCESS));
    for (int i = 0; maze[i] != NULL; i++)
        if (analyse_line_maze(maze, &i, &len) == ERROR)
            return (error_free_maze(maze, SUCCESS));
    return (start_astar(maze));
}

int get_maze(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char **maze = NULL;

    if (verif_open_file(fd) == ERROR)
        return (ERROR);
    maze = load_maze(fd, filepath);
    if (maze == NULL)
        return (ERROR);
    return (maze_or_not(maze));
}