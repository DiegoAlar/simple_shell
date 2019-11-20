#include "holberton.h"
/**
  * built_int_handler - it chooses the correct function depending on the input
  * @_args: the array with inputs
  * Return: the result of calling the function of the struct
  */
int built_in_handler(char **_args)
{
	int i = 0;
	tpe_bui arr_bu[] = {
		{"cd", fun_cd		},
		{"pwd", fun_pwd		},
		{"exit", fun_exit	},
		{"env", fun_env		}
	};
	for (; i < 4; i++)
		if (strcmp(arr_bu[i].s, _args[0]) == 0)
		{
			printf("got into if in build handler");
			return (arr_bu[i].fun(_args));
		}
	return (1);

}
