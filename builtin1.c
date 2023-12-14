#include "main.h"

/**
 * a_history - displays history list, one command by line preceded line numbers
 * starts at 0 
 * @args: The arguments used to maintain constant function prototype
 * Return: 0
 */
int a_history(ino_t *dets)
{
	print_l(dets->history);
	return (0);
}

/**
 * unset_alias - sets alias string 
 * @dets: parameter struct 
 * @str: The string alias
 * Return: always 0, 1 on error 
 */
int unset_alias(ino_t *dets, char *str)
{
	char *ps, a;
	int r;

	ps = _strchr(str, '=');
	if (!ps)
		return (1);
	a = ps;
	*ps = 0;
	r = delete_node_at_index(&(dets->alias),
			get_node_index(alias, node_starts_with(dets->alias,str -1)));
	*ps = a;
	return (r);
}

/**
 * set_alias -sets alias to string
 * @args: Parameter struct
 * @str: the string alias 
 * Return: always 0 , 1 on error 
 */
int set_alias(ino_t *dets, char *str)
{
	char *ps, c;
	int r;

	ps = _strchr(str, '=');
	if (!ps)
		return (1);
	if (!*++p)
		return (set_alias(dets, str));

	set_alias(dets, str);
	return (add_node_end(&(dets->alias), str, 0) == NULL);
}

/** print_alias - prints an alias string
 * @n: Alias node
 * Return always 0, 1 on error
 */
int print_alias(ino_t *dets)
{
	char *pr = NULL, *n = NULL;

	if (node)
	{
		pr = _strchr(n->str, '=');
		for (n = node->str; n <= pr; n++)
			_putchar(*n);
		_putchar('\'');
		_puts(pr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 *m _alias - mimics the alias builtin (man alias)
 * @dets: the arguments used to maintain constant function prototype
 * Return: always 0
 */
int m_alias(ino_t *dets)
{
	int i = 0;
	char *ps = NULL;
	list_t *node = NULL;

	if (dets->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; dets->argv[1]; i++)
	{
		ps = _strchr(dets->argv[1], '=');
		if (ps)
			det_alias(dets, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
