#include "holberton.h"
/**
  * get_string - receives a string from the promt and save it in a buffer
  * Return: a pointer of a string of char
  */
char *get_string(void)
{
	char *_str = NULL;
	size_t _size_str = 0;

	getline(&_str, &_size_str, stdin);
	printf("this is line: %s\n", _str);
	return (_str);
}
