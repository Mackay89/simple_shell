#include "main.h"

/**
 * _interactive - check if the shell is interactive mode
 * @dets: Struct address
 * Return: 1 if interactive mode , 0 otherwise
 */
int _interactive(list_t *dets)
{
	return (isatty(STDIN_FILE) && dets->readfd <= 2);
}

/**
 * _delim - checks if a character is a delimeter
 * @c: To check the char
 * @d: The delimeter string
 * Return: 1 if delimeter , 0 otherwise
 */
int _delim(char c, char *d)
{
	while (*d)
		if (*d++ == c)
			return (1);
	return(0);
}

/**
 * _isalpha - Checks for alphabetic character
 * @s: The input
 * Return: 1 if c alphabetic , 0 otherwise 
 */
int _isalpha(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}

/**
  * _atoi - converts a string to an integer
  * @s: String to be converted
  * Return: 0 if the is no number in the string or coverted number otherwise
  */
int _atoi(char *s)
{
	int i, str = 1, flag = 0, output;
	unsigned int r = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			str *= -1;

	if (s[i] >= '0' && s[i] <= '9')
	{
		flag = 1;
		r *= 10;
		r += (s[i] - '0');
	}
	else if (flag == 1)
		flag = 2;
	}
	if (str == -1)
		output = -r;
	else
		output = r;

	return (output);
}
