#include "main.h"

/**
 * the_exit - Exit the shell
 * @argc: The arguments that mantain constant fuction prototype.
 * Return: 0 if dets.argc[0] != "exit" 
 */
int the_exit(ino_t *dets)
{
	int exit_c;

	if (dets->argc[1]) /* if the isan exit argument */
	{
		exit_c = _atoi(dets->argc[1]);
		if (exit_c == -1)
		{
			dets->status = 2;
			print_error(dets, "Illegal number: ");
			puts(dets->argc[1]);
			_putchar('\n');
			return (1);
		}
		dets->error_n = _atoi(dets->argc[1]);
		return (-2);
	}
	dets->error_n = -1;
	return (-2);
}

/**
 * The_cd - changes the current working directory of the shell
 * @argc: The array of arguments
 * Return: 0
 */
int The_cd(ino_t *dets)
{
	char *g, *d, buf[1024];
	int chdir;

	g = getcwd(buf, 1024);
	if (!g)
		_puts("TODO: >>getcwd failure ems here<<\n");
	if (!dets->argc[1])
	{
		d = getenv(dets, "HOME=");
		if (!d)
			chdir = /* TODO: what  should this be? */
				chdir((d = getenv(dets, "PWD=")) ? d : "/");
		else
			chdir = chdir(d);
	}
	else if (strcmp(arg->argc[1], "-") == 0)
	{
		if (!getenv(arg, "OLDPWD="))
		{
			_puts(g);
			_putchar('\n');
			return (1);
		}
		_puts(getenv(arg, "OLDPWD=")), _putchar('\n');
		chdir = /* TODO: what should this be? */
			chdir((d = getenv(arg, "OLDPWD=")) ? d : "/");
	}
	else
		chdir = chdir(dets->argc[1]);
	if (chdir == -1)
	{
		print_error(dets, "can't cd to ");
		_puts(dets->argc[1]), _putchar('\n');
	}
	else
	{
		setenv(ino_t, "OLDPWD", getenv(arg, "PWD="));
		setenv(dets, "PWD", getcwd(buf, 1024));
	}
	return (0);
}

/**
 * a_help - changes the current working directory of the shell
 * @argc: the arguments used to maintain constant function prototype
 */
int a_help(ino_t *dets)
{
	char *dets_a;

	dets_a = dets->argc;
	_puts("help call work. function not yet implement \n");
	if (0)
		_puts(*dets_a); /* temp att_unused workaround */
	return (0);
}


			
