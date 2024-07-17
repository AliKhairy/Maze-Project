#include "maze.h"

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int create_maze(maze *this, int height, int width) {
    // Allocate memory for the maze map
    this->map = (char **)malloc(height * sizeof(char *));
    if (this->map == NULL) {
        return 100;
    }

    for (int i = 0; i < height; i++) {
        this->map[i] = (char *)malloc(width * sizeof(char));
        if (this->map[i] == NULL) {
            return 100;
        }
    }

    return EXIT_SUCCESS;
}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void free_maze(maze *this) {
    // Free the memory for each row
    for (int i = 0; i < this->height; i++)
        free(this->map[i]);

    // Free the memory for the map
    free(this->map);
}