#include"holberton.h"

/**
 *exec_handler - creates a child process and schedule execution
 *@_args: arguments to use in the execution of the program
 *Return: Integer 1 or 0
 */

int exec_handler(char **_args, char **av)
{
	tpe_comm arr_comm[] = {
		{"ls", "/bin/ls"}};
	int status, childPID, i, _flag = 0;

	childPID = fork();
	if (childPID == 0)
	{
		for (i = 0; i < 1; i++)
		{
			puts("got into the for in the  handler child process");
			if (strcmp(_args[0], arr_comm[i].str) == 0 || strcmp(_args[0], arr_comm[i].dir) == 0)
			{
				_flag = 1;
				puts("got into the if in exec handler child process");
				execve(arr_comm[i].dir, _args, NULL);
			}
		}
		if (_flag == 0)
		{
			errno = ENOENT;
			perror(av[0]);
		}

	}
	else if (childPID < 0)
	{
		perror("command not ok");
	}
	else if (childPID > 0)
	{
		do {
			waitpid(childPID, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
