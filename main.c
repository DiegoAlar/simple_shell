#include"holberton.h"

/**
 *main - function to control the shell process
 *Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	char *_str;
	char **_args;
	int _report;

	do {
		_str = get_string();
		_args = token_arg(_str);
		_report = exec_fun(_args, av, env);
		free(_str);
		free(_args);
		_str = NULL;
		_args = NULL;
		printf("value of report : %d\n", _report);

	} while (_report);

	ac = ac;
	return (0);
}
