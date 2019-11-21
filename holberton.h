#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

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

char *get_string(void);
char **token_arg(char *_str);
int exec_fun(char **_args, char **av, char **env);
int built_in_handler(char **_args);
int exec_handler(char **_args, char **av, char **env);
void *_realloc(void *ptr, int old_size, int new_size);
int fun_cd(char **);
int fun_pwd(char **);
int fun_exit(char **);
int fun_envi(char **);
char *func_env(char *_com, char **env);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);

#endif
