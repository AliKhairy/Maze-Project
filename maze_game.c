#include "maze.h"
/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(maze *this, coord *player)
{
    // make sure we have a leading newline.
    printf("\n");
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            // decide whether player is on this spot or not
            if (player->x == j && player->y == i)
            {
                printf("X");
            }
            else
            {
                printf("%c", this->map[i][j]);
            }
        }
        // end each row with a newline.
        printf("\n");
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(maze *this, coord *player, char direction)
{
    int new_x = player->x;
    int new_y = player->y;

    switch (direction)
    {
    case 'W':
    case 'w':
        new_y--;
        break;

    case 'A':
    case 'a':
        new_x--;
        break;
    
    case 'D':
    case 'd':
        new_x++;
        break;

    case 'S':
    case 's':
        new_y++;
        break;
    case 'M':
    case 'm':
        print_maze(this, player);
        break;
    default:
        printf("Please pick either W, A, S, D or M. ");
        break;
    }
     if (new_x >= 0 && new_x < this->width && new_y >= 0 && new_y < this->height && this->map[new_y][new_x] != '#') {
        player->x = new_x;
        player->y = new_y;
    }
    else {
        printf("Invalid move. ");
    }
    

}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(maze *this, coord *player)
{
    if(player->x == this->end.x && player->y == this->end.y) {
        return 1;
    } else {
        return 0;
    }
}