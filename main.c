#include"holberton.h"

/**
 *main - function to control the shell process
 *Return: 0 on success
 */

int main(void)
{
	char *_str;
	char **_args;
	int _report, i = 0;

	do {
		_str = get_string();
		_args = token_arg(_str);
		while (_args[i])
		{
			printf("%s\n", _args[i]);
			i++;

		}
		_report = exec_fun(_args);
		free(_str);
		free(_args);
		_str = NULL;
		_args = NULL;
		i = 0;
	} while (_report);

	return (0);
}
