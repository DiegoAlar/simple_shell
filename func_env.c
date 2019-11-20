#include "holberton.h"
/**
  * func_env - this function will search for a PATH
  * @_com: the command to search in the PATH
  * @env: an array of arrays containing the path
  * Return: a string containing the path or NULL
  */
char *func_env(char *_com, char **env)
{
	int i , j;
	char *_exe_str;
	char *_delim = "=:";
	char *key = "PATH";
	char *res;

	for (i = 0; env[i]; i++)
	{
		_exe_str = strtok(env[i], _delim);
		if (strcmp(_exe_str, key) == 0)
		{
			_exe_str = strtok(NULL, _delim);
			res = strcat(_exe_str, _com);
			if (access(res, F_OK) == 0)
			       return (res);
		}
	}
	return (NULL);
}
