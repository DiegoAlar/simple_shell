#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 *struct bu_in - structure to reference the right built in function
 *@s: string to be evaluated
 *@fun: function correspont to the string
 */
typedef struct bu_in
{
	char *s;
	int (*fun)(char **);
} tpe_bui;

/**
 *struct exec_hand - structure to reference the right executable
 *@str: string to be evaluated
 *@dir: string indicating the executable file
 */

typedef struct exec_hand
{
	char *str;
	char *dir;
} tpe_comm;
char *get_string(void);
char **token_arg(char *_str);
int exec_fun(char **_args);
int built_in_handler(char **_args);
int exec_handler(char **_args);


#endif
