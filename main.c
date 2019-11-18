#include"holberton.h"

/**
 *main - function to control the shell process
 *Return: 0 on success
 */

int main(void)
{
	char *_str;
	char **_args;
	int _report;

	do {
		_str = get_string();
		_args = token_arg(_str);
		_report = exec_fun(_args);
		free(_str);
		free(_args);
	} while (_report);

	return (0);
}
