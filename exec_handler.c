#include"holberton.h"

/**
 *exec_handler - creates a child process and schedule execution
 *@_args: arguments to use in the execution of the program
 *@av: parameter to indicate the name of the shell
 *Return: Integer 1 or 0
 */

int exec_handler(char **_args, char **av, char **env)
{
	int status, childPID, _flag = 0, kill_is;
	char *_str_ev;

	_str_ev = NULL;
	kill_is = 1;
	kill_is = isatty(STDIN_FILENO);
	puts("entered exec_handler");
	_str_ev = func_env(_args[0], env);
	if (_str_ev != NULL)
	{
		puts("entered if in exec handler");
		_flag = 1;
		childPID = fork();
		if (childPID == 0)
		{
			execve(_str_ev, _args, NULL);
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
	}
	if (_flag == 0)
	{
		errno = ENOENT;
		perror(av[0]);
	}
	if (kill_is == 0)
		return (0);
	return (1);
}
