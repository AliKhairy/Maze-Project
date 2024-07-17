#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// Defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

typedef struct __Coord {
    int x;
    int y;
} coord;

typedef struct __Maze {
    char **map;
    int height;
    int width;
    coord start;
    coord end;
} maze;

int create_maze(maze *this, int height, int width);
void free_maze(maze *this);
int get_width(FILE *file);
int validate_start_end(maze *this);
int get_height(FILE *file);
int read_maze(maze *this, FILE *file);
void print_maze(maze *this, coord *player);
void move(maze *this, coord *player, char direction);
int has_won(maze *this, coord *player);

#endif /* MAZE_H */