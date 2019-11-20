#include"holberton.h"

/**
 *exec_fun - function to decide the execution based on arguments
 *@_args: arguments
 *Return: 1 or 0 integer
 */

int exec_fun(char  **_args, char **av)
{
	int i;
	char *_build_do[] = {"cd", "pwd", "exit", "env"};
	/*char *_exec_command[] = {"ls", "/bin/ls"};*/

	for (i = 0; i < 4; i++)
	{
		if (strcmp(_args[0], _build_do[i]) == 0)
		{
			printf("got into if");
			return (built_in_handler(_args));
		}
	}
	/*for (j = 0; j < 2; j++)
	{
		if (strcmp(_args[0], _exec_command[j]) == 0)
		return (exec_handler(_args));
	}
	errno = ENOENT;
	perror(av[0]);
	return (1);*/
	return (exec_handler(_args, av));
}
