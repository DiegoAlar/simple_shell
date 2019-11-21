#include"holberton.h"

/**
 *exec_handler - creates a child process and schedule execution
 *@_args: arguments to use in the execution of the program
 *@av: parameter to indicate the name of the shell
 *@env:environ variable
 *Return: Integer 1 or 0
 */

int exec_handler(char **_args, char **av, char **env)
{
	int status, childPID, _flag = 0, kill_is;
	char *_str_ev;

	_str_ev = NULL;
	kill_is = 1;
	kill_is = isatty(STDIN_FILENO);
	if (access(_args[0], F_OK) == 0)
		_str_ev = _args[0];
	else
	{
		_str_ev = func_env(_args[0], env);
		_flag++;
	}
	if (_str_ev != NULL)
	{
		_flag++;
		childPID = fork();
		if (childPID == 0)
			execve(_str_ev, _args, NULL);
		else if (childPID < 0)
			perror("command not ok");
		else if (childPID > 0)
		{
			do {
				waitpid(childPID, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	if (_flag == 0 || (_flag == 1 && _str_ev == NULL))
	{
		errno = ENOENT;
		perror(av[0]);
	}
	if (_flag == 2)
		free(_str_ev);
	if (kill_is == 0)
		return (0);
	return (1);
}
