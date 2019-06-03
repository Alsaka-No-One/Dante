/*
** EPITECH PROJECT, 2019
** solver
** File description:
** load_maze_two
*/

#include "solver.h"

int get_nb_line_of_file(char *str)
{
    int len = 0;
    int status = 0;

    for (int i = 0; status == 0; i++) {
        if (str[i] == '\n' || str[i] == '\0')
            len++;
        if (str[i] == '\0')
            status = 1;
    }
    return (len);
}

char *get_line_file(char *str, int *size, int *i)
{
    char *line_maze = malloc(sizeof(char) * (*size + 1));
    int j = 0;

    if (line_maze == NULL)
        return (NULL);
    while (*size != 0) {
        line_maze[j] = str[*i - *size];
        (*size)--;
        j++;
    }
    line_maze[j] = '\0';
    if (str[*i] == '\n' && str[*i + 1] == '\0')
        (*i)++;
    return (line_maze);
}

char **fill_maze(char **maze, char *str)
{
    int line = 0;
    int size = 0;
    int status = 0;

    for (int i = 0; status == 0; i++) {
        if (str[i] == '\0' || str[i] == '\n') {
            maze[line] = get_line_file(str, &size, &i);
            line++;
            size = 0;
        } else
            size++;
        if (str[i] == '\0')
            status = 1;
        if (line > 0 && maze[line - 1] == NULL)
            return (NULL);
    }
    if (line == 0)
        return (NULL);
    maze[line] = NULL;
    return (maze);
}

char **load_maze(int fd, char *filepath)
{
    char **maze = NULL;
    char *buffer = NULL;
    struct stat size;

    stat(filepath, &size);
    buffer = malloc(sizeof(char) * (size.st_size + 1));
    if (buffer == NULL || read(fd, buffer, size.st_size + 1) == -1)
        return (NULL);
    buffer[size.st_size] = '\0';
    close(fd);
    maze = malloc(sizeof(char *) * (get_nb_line_of_file(buffer) + 2));
    if (maze == NULL)
        return (NULL);
    maze = fill_maze(maze, buffer);
    if (maze == NULL)
        return (NULL);
    free(buffer);
    return (maze);
}