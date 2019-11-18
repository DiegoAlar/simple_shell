#include"holberton.h"

/**
 *token_arg - tokenization of command line string
 *@_str: string created with input from command line
 *Return: arguments, pointer of a pointer
 */

char **token_arg(char *_str)
{
	int i = 0, strs_size = 64;
	char **_args;
	char *_arg;

	_args = malloc(strs_size * (sizeof(char *)));
	_arg = strtok(_str, " ");
	while (_arg)
	{
		_args[i] = _arg;
		if (i >= strs_size)
		{
			_args = _realloc(_args, strs_size * (sizeof(char *)));
			if (!_args)
			{
				perror("Unable to allocate memory\n");
				exit(99);
			}
		}
		_arg = strtok(NULL, " ");
		i++;
	}
	_args[i] == NULL;
	return (_args);
}
