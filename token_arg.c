#include"holberton.h"

/**
 *token_arg - tokenization of command line string
 *@_str: string created with input from command line
 *Return: arguments, pointer of a pointer
 */

char **token_arg(char *_str)
{
	int i = 0, strs_size = 64, newSize = 0, ss, ns;
	char **_args;
	char *_arg;

	_args = malloc(strs_size * (sizeof(char *)));
	if (!_args)
	{
		perror("Allocation unsucceded\n");
		exit(98);
	}
	_arg = strtok(_str, " ");
	while (_arg != NULL)
	{
		_args[i] = _arg;
		i++;
		if (i >= strs_size)
		{
			newSize = strs_size + 64;
			ss = (strs_size * (sizeof(char *)));
			ns = (strs_size * (sizeof(char *)));
			_args = _realloc(_args, ss, ns);
			strs_size = newSize;
			if (!_args)
			{
				perror("Unable to allocate memory\n");
				exit(99);
			}
		}
		_arg = strtok(NULL, " ");
	}
	_args[i] == NULL;
	return (_args);
}
