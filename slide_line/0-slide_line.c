#include "slide_line.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * slide_line - Slides and merges an array of integers
 *
 * @line: Points to an array of integers containing size elements
 * @size: Number of elements in @array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        if (line[i] == line[j])
                        {
                            line[i] *= 2;
                            line[j] = 0;
                            break;
                        }
                        break;
                    }
                }
            }
        }
        k = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                line[k] = line[i];
                if (k != i)
                {
                    line[i] = 0;
                }
                k++;
            }
        }

        return (1);
    }
    else if (direction == SLIDE_RIGHT)
    {

        for (i = size - 1; i > 0; i--)
        {
            if (line[i] != 0)
            {
                for (j = i - 1; j < size; j--)
                {
                    if (line[j] != 0)
                    {
                        if (line[i] == line[j])
                        {
                            line[i] *= 2;
                            line[j] = 0;
                            break;
                        }
                        break;
                    }
                }
            }
        }

        k = size - 1;
        for (i = size - 1; i < size; i--)
        {
            if (line[i] != 0)
            {
                line[k] = line[i];
                if (k != i)
                {
                    line[i] = 0;
                }
                k--;
            }
        }

        return (1);
    }

    return (0);
}
