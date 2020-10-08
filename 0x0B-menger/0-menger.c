#include "menger.h"
/**
 * menger - funtion draws a 2D Menger Sponge
 * @level: level is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int n, j, x, y, size;
	char s;

	size = pow(3, level);

	for (n = 0; n < size; n++)
	{
		for (j = 0; j < size;)
		{
			s = '#';
			x = n;
			y = j++;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					s = ' ';
				}
				x /= 3;
				y /= 3;
			}
			printf("%c", s);
		}
		printf("\n");
	}
}
