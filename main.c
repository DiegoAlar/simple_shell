#include"holberton.h"
/**
 *main - function to control the shell process
 *@ac:main argument, number of arguments
 *@av:main argument, array of arguments
 *@env:main argument, environmental variable
 *Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	char *_str = NULL;
	char **_args = NULL;
	int _report = 1, kill_is = 0, cicles = 1;
	size_t _size_str;
	char *no_command = "\n";

	kill_is = 1;
	kill_is = isatty(STDIN_FILENO);
	if (kill_is)
		_printf("#cisfun$ ");


	while (_report && (getline(&_str, &_size_str, stdin) != EOF))
	{
		if (_strcmp(_str, no_command) != 0)
		{
			_args = token_arg(_str);
			_report = exec_fun(&cicles, _args, av, env);
			free(_str);
			free(_args);
			_str = NULL;
			_args = NULL;
			if (kill_is)
				_printf("#cisfun$ ");

			cicles++;
		}
		else
			_printf("#cisfun$ ");

	}

	if (kill_is)
		_printf("\n");

	free(_str);
	free(_args);
	ac = ac;
	return (0);
}
