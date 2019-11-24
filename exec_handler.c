#include"holberton.h"

/**
 *exec_handler - creates a child process and schedule execution
 *@_args: arguments to use in the execution of the program
 *@av: parameter to indicate the name of the shell
 *@env:environ variable
 *@cicles: number of times parameters are passed
 *Return: Integer 1 or 0
 */

int exec_handler(int *cicles, char **_args, char **av, char **env)
{
	int status, childPID, _flag = 0;
	char *_str_ev = NULL;
	DIR *dir_to_close;
	struct stat *bf;

	bf = malloc(sizeof(struct stat));
	if (stat(_args[0], bf) == 0 && S_ISREG(bf->st_mode))
		_str_ev = _args[0];
	else if (stat(_args[0], bf) == 0 && S_ISDIR(bf->st_mode))
	{
		_printf("%s: %d: %s: Permission denied\n", av[0], *cicles, _args[0]);
		free(bf);
		return (1);
	}
	else if (_args[0][0] == '/')
	{
		dir_to_close = opendir(_args[0]);
		if (dir_to_close == NULL)
		{
			_printf("%s: %d: %s: command not found\n", av[0], *cicles, _args[0]);
			free(bf);
			return (1);
		}
		else
		{
			closedir(dir_to_close);
			_printf("%s: %d: %s: Permission denied\n", av[0], *cicles, _args[0]);
			free(bf);
			return (1);
		}
	}
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

		_printf("%s: %d: %s: not found\n", av[0], *cicles, _args[0]);
	}
	free(bf);
	if (_flag == 2)
		free(_str_ev);
	return (1);
}
