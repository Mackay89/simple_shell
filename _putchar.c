#include "main.h"

/**
 * _myputchar - writes the character c to stderr
 * @c: the character to print
 * Return: always 1
 * On error, -1 is return, and errno is set appropriately
 */
int _myputchar(char c)
{
	static int i;
	static char buffer[WRIRE_BUF_SIZE];

	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * _myputs - prints an input string
 * @str: string to be printed
 * Return: 0
 */
void _myputs(char *str)
{
	int a = 0;

	if (!str)
	
	
		return (0);
	while (str[a] != '\0')
	{
		_myputchar(str[a]);
		a++;
	}
}

/**
 * _eputfd - write the character c to be given fd
 * @str: character to print
 * @fd: the filedescriptor to write to
 * Return: number char put
 */
int _eputfd(char s, int fd)
{
	 int i;
	
	if (!str)
		return (0);
	while (*str)
	{
		i += _eputfd(*str++,\fd);
	}
	return (i);
}

/** 
 * _putsfd - write the character c to given fd
 * @s: character to be printed
 * @fd:  the filedescriptor towrite to
 * Return: 1
 * On error, -1 is return, and errno is set appropriately
 */
int _putsfd(char c, int fd)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (s == BUFFER_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (s != BUFFER_FLUSH)
		buffer[i++] = s;
	return (1);
}
