/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

static const int SUCCESS = 0;
static const int ERROR = 84;

typedef struct coord_s {
    int width;
    int height;
    int x;
    int y;
    int status;
} coord_t;

typedef struct pile_s {
    int x;
    int y;
} pile_t;

int check_input(int argc, char **argv);
int find_maze(char **argv);
int perfect_maze(char **maze, coord_t size, pile_t *pile);
int imperfect_maze(char **maze, coord_t size, pile_t *pile);
int display_maze(char **maze, pile_t *pile);
int strange_maze(char **maze, coord_t size, pile_t *pile);
void algo_perfect(char **maze, pile_t *pile, coord_t *size, int *pile_index);
void fill_pile(pile_t *pile, int *pile_index, coord_t *path);
int check_up(char **maze, coord_t *size, int x, int y);
int check_left(char **maze, coord_t *size, int x, int y);
int check_right(char **maze, coord_t *size, int x, int y);
int check_down(char **maze, coord_t *size, int x, int y);
int check_direction(char **maze, int x, int y);
void check_direction_pile(char **maze, coord_t *size, pile_t *pile,
    int *pile_index);
int start(coord_t *size);
int str_isnum(char *str);

#endif
