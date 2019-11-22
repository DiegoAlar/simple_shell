#include"holberton.h"
/**
 *main - function to control the shell process
 *Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	char *_str = NULL;
	char **_args = NULL;
	int _report = 1, kill_is = 0, cicles = 1;
	size_t _size_str;

	kill_is = 1;
	kill_is = isatty(STDIN_FILENO);
	if (kill_is)
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	while (_report && (getline(&_str, &_size_str, stdin) != EOF))
	{
		_args = token_arg(_str);
		_report = exec_fun(&cicles, _args, av, env);
		free(_str);
		free(_args);
		_str = NULL;
		_args = NULL;
		if (kill_is)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		cicles++;
	}

	if (kill_is)
		write(STDOUT_FILENO, "\n", 1);
	ac = ac;
	return (0);
}
