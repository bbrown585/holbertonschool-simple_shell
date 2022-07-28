#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * str_tok - string token
 * @str: string
 * Return: token
 */
char **str_tok(char *str)
{
	static char **tokens;
	int i = 0;
	char *buffer = strdup(str);
	char *token;
	int len = 0;
	int numtokens = 0;

	while (buffer[len])
	{
		if (buffer[len] == ' ')
			numtokens++;
		len++;
	}

	token = malloc
	tokens[i] = token;
	i++;
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		tokens[i] = token;
		i++;
}

	return (tokens);
}
