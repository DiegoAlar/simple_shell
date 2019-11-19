#include"holberton.h"

/**
 *exec_handler - creates a child process and schedule execution
 *@_args: arguments to use in the execution of the program
 *Return: Integer 1 or 0
 */

int exec_handler(char **_args)
{
	tpe_comm arr_comm[] = {
		{"ls", "/bin/ls"}}
	int status;

	PID = fork();
	if (PID == 0)
	{
		for (i = 0; i < 1; i++)
		{
			if (args[0] == arr_comm[i].str || args[0] == arr_comm[i].dir)
				execve(arr_comm[i].dir, args);
		}
	}
	else if (PID < 0)
		perror("command not ok");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
