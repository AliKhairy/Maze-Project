#include "maze.h"

/**
 * @brief Validate and return the width of the mazefile
 *
 * @param file the file pointer to check
 * @return int 3 for error, or a valid width (5-100)
 */
int get_width(FILE *file)
{
    rewind(file);
    int width = 0;
    char character;

    // Read the first non-newline character
    while ((character = fgetc(file)) && character != '\n')
    {
        if (character == '#' || character == ' ' || character == 'S' || character == 'E')
            width++;
        else {
            printf("bad character (width) bro sorry");
            exit(EXIT_MAZE_ERROR);
        }
        
    }

    // Check if the width is within the valid range
    if (width >= MIN_DIM && width <= MAX_DIM)
        return width;
    else{
        printf("incorrect width brosky");
        exit(EXIT_MAZE_ERROR);
    }
    
}

/**
 * @brief Find start and end points while validating them.
 *
 * @param this Maze struct to be used.
 * @return int 0 for success, int 3 for error.
 */
int validate_start_end(maze *this) 
{
    int startFound = 0, endFound = 0;
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            // Check if multiple startpoints
            if (this->map[i][j] == 'S')
            {
                if (startFound == 1)
                {
                    exit(EXIT_MAZE_ERROR);
                }
                this->start.x = j;
                this->start.y = i;
                startFound = 1;
            }
            
            // Check if multiple endpoints
            if (this->map[i][j] == 'E')
            {
                if (endFound == 1)
                {
                    exit(EXIT_MAZE_ERROR);
                }
                this->end.x = j;
                this->end.y = i;
                endFound = 1;
            }   
        }  
    }
    if (startFound == 1 && endFound == 1)
            {
                return EXIT_SUCCESS;
            } else {
                return EXIT_MAZE_ERROR;
            }  
}

/**
 * @brief Validate and return the height of the mazefile while also
 *        validating every row.
 *
 * @param file the file pointer to check
 * @return int 3 for error, or a valid height (5-100)
 */
int get_height(FILE *file)
{
    rewind(file);
    int height = 0;
    char c;
    char previous_c;
    int count = 0;
    int width = get_width(file);
    while ((c = fgetc(file)) && c != EOF)
    {
        if (c == '#' || c == ' ' || c == 'S' || c == 'E' || c == '\n')
        {
            count++;
            if (c == '\n')
            {
                height++;
                if (c == '\n' && previous_c == '\n')
                {
                    continue;
                }

                // Validate every row
                if (count == width+1)
                {
                    count = 0;
                } else {
                    printf("inconsistent width");
                    exit(EXIT_MAZE_ERROR);
                }
            }
        } else {
            printf("bad character (height)");
            exit(EXIT_MAZE_ERROR);
            
        }
        previous_c = c;
    }

    if (height+1 >= MIN_DIM && height+1 <= MAX_DIM)
    {
        return height+1;
        
    }
    else {
        printf("incorrect heigh dim bro sorry");
        printf("%d", height+1);
        exit(EXIT_MAZE_ERROR);
    }
}