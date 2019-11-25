#include"holberton.h"

/**
 *stat_fun - evaluates initial condition of arguments
 *@_str: pointer of pointer to evaluate
 *@_fl: flag to control pointer free
 *@_com: command in the shell
 *@env:environ variable
 *@c: count the cicles
 *@av_0:first main argument
 *Return: Integer 1 or 0
 */

int stat_fun(char **_str, int *_fl, char *_com, int c, char *av_0, char **env)
{
	DIR *dir_to_close;
	struct stat  *bf;

	bf = malloc(sizeof(struct stat));
	if (bf == NULL)
		return (1);
	if (stat(_com, bf) == 0 && S_ISREG(bf->st_mode))
		*_str = _com;
	else if (stat(_com, bf) == 0 && S_ISDIR(bf->st_mode))
		_printf("%s: %d: %s: Permission denied\n", av_0, c, _com);
	else if (_com[0] == '/')
	{
		dir_to_close = opendir(_com);
		if (dir_to_close == NULL)
		{
			_printf("%s: %d: %s: command not found\n", av_0, c, _com);

		}
		else
		{
			closedir(dir_to_close);
			_printf("%s: %d: %s: Permission denied\n", av_0, c, _com);

		}
	}
	else
	{
		*_str = func_env(_com, env);
		*_fl += 1;
	}
	free(bf);
	return (1);
}
