#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
typedef struct bu_in
{
	char *s;
	int (*fun)(char **);
} tpe_bui;
typedef struct exec_hand
{
	char *str;
	char *dir;
} tpe_comm;
char * get_string(void);
char ** token_arg(char * _str);
int exec_fun(char ** _args);
int built_in_handler(char **_args);
int exec_handler(char **_args);




#endif
