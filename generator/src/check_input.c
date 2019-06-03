/*
** EPITECH PROJECT, 2019
** generator
** File description:
** check_input
*/

#include "generator.h"

int str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int check_input(int argc, char **argv)
{
    if (argc < 3 || argc > 4) {
        write(2, "Invalid number of arguments\n", 28);
        return (ERROR);
    }
    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || str_isnum(argv[1]) == 0
        || str_isnum(argv[2]) == 0) {
        write(2, "The maze must be rectangular! (number > 1)\n", 43);
        return (ERROR);
    }
    if ((atoi(argv[1]) == 1 && atoi(argv[2]) < 2)
        || (atoi(argv[2]) == 1 && atoi(argv[1]) < 2)) {
        write(2, "The maze must be rectangular!\n", 30);
        return (ERROR);
    }
    if (argc == 4)
        if (strcmp(argv[3], "perfect") != 0) {
            fprintf(stderr
                , "Invalid argument: [USAGE] = ./generator x y [perfect]\n");
            return (ERROR);
        }
    return (find_maze(argv));
}