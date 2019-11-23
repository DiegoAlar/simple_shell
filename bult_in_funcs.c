#include "holberton.h"
/**
  *
  *
  *
  *
  */
int fun_cd(char **_args)
{
	printf("Entered fun_cd function: %s\n", _args[0]);
	return (1);
}

/**
  *
  *
  *
  *
  */
int fun_pwd(char **_args)
{
	printf("Entered fun_pwd function: %s\n", _args[0]);
	return (1);
}

/**
  *
  *
  *
  *
  */
int fun_exit(char **_args)
{
	char *ex = "exit";

	if (strcmp(_args[0], ex) == 0)
	{

		return (0);
	}
	return (1);
}

/**
  *
  *
  *
  *
  */
int fun_envi(char **_args)
{
	printf("Entered fun_env function: %s\n", _args[0]);
	return (1);
}

