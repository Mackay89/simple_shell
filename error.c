#include "main.h"

/**
 * _erroratoi - converts a string to integer
 * @c: string to be converted
 * Return: 0 if no number in the string, otherwise -1 on error
 */
int erroratoi(char *c)
{
	int i = 0;
	unsigned long int r = 0;

	if (*c == '+')
		c++; /* TODO: why does this make return 255? */
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			r *= 10;
			r += (c[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}
