/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct coord_s
{
    int x;
    int y;
} coord_t;

typedef struct list_s
{
    coord_t parent;
    coord_t pos;
    struct list_s *next;
} list_t;

int analyse_arg(int ac, char **av);
int verif_open_file(int fd);
void free_array(char **maze);
int analyse_line_maze(char **maze, int *i, size_t *len);
int maze_or_not(char **maze);
int get_maze(char *filepath);
int get_nb_line_of_file(char *str);
char *get_line_file(char *str, int *size, int *i);
char **fill_maze(char **maze, char *str);
char **load_maze(int fd, char *filepath);
int get_nb_col(char *maze);
int get_nb_line(char **maze);
int start_astar(char **maze);
coord_t initialize_coord(int x, int y);
char delete_charac(char maze);
int delete_trace(char **maze, list_t **c_list, list_t **o_list);
int print_path_in_maze(char **maze, list_t *c_list);
int print_maze(char **maze);
list_t *initialize_list(void);
int check_end(list_t *c_list, coord_t *arrive);
int check_value_case(char **maze, coord_t coord);
void fill_start_list_astar(list_t **list, coord_t parent, coord_t pos);
int get_old_possibility(char **maze, list_t **c_list, list_t **o_list);
void free_list(list_t *list);
int error_maze_possibility(char **maze, list_t **c_list, list_t **o_list);
int check_case_up(int *status, list_t **o_list, list_t **c_list, coord_t *pos);
int check_case(char **maze, list_t **o_list, list_t **c_list, coord_t *arrive);
int check_case_down(int *status,
        list_t **o_list, list_t **c_list, coord_t *pos);
int check_case_left(int *status,
        list_t **o_list, list_t **c_list, coord_t *pos);
int check_case_right(int *status, list_t **c_list, coord_t *pos, char **maze);
int error_free_maze(char **maze, int ret);

static const int SUCCESS = 0;
static const int ERROR = 84;

#endif
