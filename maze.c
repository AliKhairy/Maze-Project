/**
 * @file maze.c
 * @author Ali Khairy
 * @brief Code for the maze game for COMP1921 Assignment 2
 * NOTE - You can remove or edit this file however you like - this is just a provided skeleton code
 * which may be useful to anyone who did not complete assignment 1.
 */

#include "maze.h"

int main(int argc, char *argv[])
{
    // check args
    if (argc != 2) {
        printf("Usage: %s <mazefile>\n", argv[0]);
        return EXIT_ARG_ERROR;
    }
    // set up some useful variables (you can rename or remove these if you want)
    coord *player = malloc(sizeof(coord));
    maze *this_maze = malloc(sizeof(maze));
    FILE *f;

    // open and validate mazefile
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        exit(EXIT_FILE_ERROR);
    }
    this_maze->width = get_width(f);
    this_maze->height = get_height(f);
    create_maze(this_maze, this_maze->height, this_maze->width);
    // read in mazefile to struct
    read_maze(this_maze, f);
    fclose(f);
    // maze game loop
    player->x = this_maze->start.x;
    player->y = this_maze->start.y;
    char direction;
    while (has_won(this_maze, player) == 0)
    {
        printf("Enter move: ");
        direction = getchar();
        if (direction == '\n')
        {
            continue;
        }
        
        while (getchar() != '\n');
        move(this_maze, player, direction);
    }
    
    // win
    printf("Thy has won.\n");
    // return, free, exit
    free_maze(this_maze);
    free(player);
    return EXIT_SUCCESS;
}