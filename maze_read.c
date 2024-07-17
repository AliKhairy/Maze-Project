#include "maze.h"

/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 3 on fail
 */
int read_maze(maze *this, FILE *file)
{
    rewind(file);
   // Read each line from the file and copy it into the maze map
    char buffer[MAX_DIM + 2]; // Maximum size of line in maze + 2 (for newline and null terminator)
    int row = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Trim trailing newline character, if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        // Allocate memory for the current row
        this->map[row] = (char *)malloc((len + 1) * sizeof(char));
        if (this->map[row] == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        // Copy characters from buffer to maze map
        strcpy(this->map[row], buffer);

        // Validate row length
        if ((int)len != this->width) {
            printf("Invalid maze file format: Inconsistent row length.\n");
            exit(EXIT_FAILURE);
        }

        row++;
    }

    // Validate the start and end points
    validate_start_end(this);

    return EXIT_SUCCESS;
}