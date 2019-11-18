#include"holberton.h"

/**
 *token_arg - tokenization of command line string
 *@_str: string created with input from command line
 *Return: arguments, pointer of a pointer
 */

char **token_arg(char *_str)
{
	int i = 0, strs_size = 0;
	char **_args;
	char *_arg;

	while (_str[strs_size])
	{
		strs_size++;
	}
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
		_arg = strtok(NULL, " ");
		i++;
	}
	_args[i] == NULL;
	return (_args);
}
