#include "main.h"

/**
 * _env - prints the current environment variable
 * @dets: The argument is used to maintain constant function prototype
 * Return: always 0
 */
int _env(ino_t *dets)
{
	print_list_str(dets->env);

	return (0);
}

/**
 * _getenv - get the value of an environment variable
 * @dets: The arguments are used to maintain constant function prototype
 * @name: The env var name
 * Return: value of the environment
 */
char *_getenv(ino_t *dets, const char *name)
{
	ino_t *node = dets->env;
	char *env;

	while (node)
	{
		p = starts_with(node->str,name);
		if (p && *env)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * setenv - initialize a new environment variableor modify an existing one
 * @dets: The arguments is used to maintain constant function prototype
 * Return: always 0
 */
int setenv(ino_t *dets)
{
	if (dets->argc != 3)
	{
		puts("Incorrect number of arguments\n");
		return (1);
	}
	if (setenv(dets, dets->argc[1], dets->argc[2]))
		return (0);
	return (1);
}

/**
 * a_unsetenv - remove an environment variable
 * @dets: the arguments is used to maintain constant function prototype
 * Return always 0
 */
int a_unsetenv(ino_t *dets)
{
	int a;

	if (dets->argc == 1)
	{
		_puts("Too few arguments.\n");
		return (1);
	}
	for (a = 1; a <= dets->argc; a++)
		a_unsetenv(dets, dets->argv[a]);
	return (0);
}

/**
 * env_list - populates the environment list
 * @dets: the argument used to maintain constant function prototype
 * Return: 0
 */
int env_list(ino_t *dets)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	dets->env = node;
	return (0);
}
