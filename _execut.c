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
		if (strcmp(_args[0], _build_do[i]) == 0)
		{
			return (built_in_handler(_args));
		}
	}
	for (j = 0; j < 1; j++)
	{
		if (_args[0] == _exec_command[j])
			return (exec_handler(_args));
	}
	printf("entered here");
	perror(_args[0]);
	return (1);
}
