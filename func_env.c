#include "holberton.h"
/**
  * func_env - this function will search for a PATH
  * @_com: the command to search in the PATH
  * @env: an array of arrays containing the path
  * Return: a string containing the path or NULL
  */
char *func_env(char *_com, char **env)
{
	int i;
	char *_exe_str;
	char *_delim = "=:";
	char *key = "PATH";
	char *res, char **dirs_in_PATH;

	puts("entered func_env");
	for (i = 0; env[i]; i++)
	{
		_exe_str = strtok(env[i], _delim);
		printf("%s\n", _exe_str);
		if (strcmp(_exe_str, key) == 0)
		{
			puts("entered if in func_env");
			while (_exe_str)
			{

				 printf("%s\n", _exe_str);
				_exe_str = strtok(NULL, _delim);
				res = strcat(_exe_str, _com);
				if (access(res, F_OK) == 0)
			       		return (res);
				free(res);
			}
		}
	}
	return (NULL);
}
