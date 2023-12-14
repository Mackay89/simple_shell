#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

/* for read/write buffer */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUFFER_FLUSH -1

/* for command chaining */
#define CMD_NORM 0
#define CMD_OR   1
#define CMD_AND  2
#define CMD_CHAIN 3

/* for convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

#define HIST_FILE	".simple_shell_history
#define HIIST_MAX 	4906

extern char **enveron;

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK  0

/**
 * struct liststr - singly linke list
 * @n: number field
 * @s: string
 * @next: points to next node
 */
typedef struct liststr
{
	int n;
	char *s;
	struct liststr *next;
}list_t;

/**
 * struct builtin - contains builtin string and related function
 * @type: builtin command flag
 * @func: the function 
 */
typedef struct builtin
{
	char *type;
	int (*func)(ino_t *);
} builtin_table;

/* toem_shloop.c */
int hsh(ino_t * , char **);
int find_builtin(ino_t *);
void find_cmd(ino_t *);
void fork_cmd(ino_t *);

/* toem_parse.c */
int is_cmd(ino_t *, char *);
char *dup_chars(char *, int, int);
char * find_path(ino_t *, char *, char *);

/* loophsh.c */
int loophsh( char **);

#endif



