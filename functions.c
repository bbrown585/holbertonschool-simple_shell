#include <stdio.h>
#include "shell.h"

/**
 * _strlen - string length
 * @s: string
 * Return:0
 */
int _strlen(char *s)
{
	int length = 0;

	while
(s[length] != '\0') length++;
	return (length);
}

/**
 * *_strcpy - copy
 * @dest: string dest
 * @src: string source
 * Return: 0.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compare string
 * @s1: string
 * @s2: string
 *
 * Return: 0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		break;
	}
	return (*s1 - *s2);
}
