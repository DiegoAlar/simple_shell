#include"holberton.h"

/**
 *exec_fun - function to decide the execution based on arguments
 *@_args: arguments
 *Return: 1 or 0 integer
 */

int exec_fun(char  **_args)
{
	int i, j;
	char *_build_do[] = {"cd", "pwd", "exit", "env"};
	char *_exec_command[] = {"ls"};

	for (i = 0; i < 4; i++)
	{
		if (args[0] == build_do[i])
			return (built_in_handler(args));
	}
	for (j = 0; j < 1; j++)
	{
		if (args[0] == exec_command[j])
			return (exec_handler(args));
	}
	perror(args[0]);
	return (1);
}
