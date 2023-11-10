#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
	int i, j, size, x, y;
	char c;

	size = pow(3, level);
	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			c = '#';
			while (x > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					c = ' ';
				x /= 3;
				y /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
