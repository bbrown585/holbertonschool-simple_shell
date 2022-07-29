#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "shell.h"

char **make_av(char *);
void print_arrary(char **av);
int execute(char **command);
/**
 * main - entry
 * @av: value
 * @ac: count
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	char **command;
	size_t bufsize = 0;

	while (ac)
	{
		printf("($) ");

		getline(&buffer, &bufsize, stdin);

		if (strcmp(buffer, "exit") == 0)
			break;
		{
			command = make_av(buffer);
			execute(command);
			if (execute(command) == -1)
			break;
		}
	}
	free(buffer);
	free(av);

	return (0);
}
/**
 * execute- fork
 * @command: array of strings
 * Return: -1.
 */
int execute(char **command)
{
	pid_t is_kid;

	is_kid = fork();

	if (is_kid != 0)
	{
		wait(NULL);
		return (0);
	}
	if (is_kid == 0)
	{
		execve(command[0], command, NULL);
		if (execve(command[0], command, NULL) == -1)
		{
			perror("Error: ");
			printf("%s", command[0]);
			return (-1);
		}
	}

	return (0);
}
/**
 * make_av - fill the array
 * @str: string
 * Return: pointer
 */

char **make_av(char *str)
{
	char *buffer = strdup(str);
	char *argument;
	char prev = 0;
	int i = 0, numArgs = 0;

	while (buffer[i])
	{
		if (buffer[i] == ' ' && prev != ' ')
			numArgs++;
		prev = buffer[i];
		i++;
	}

	av = malloc(sizeof(*av) * (numArgs + 2));

	argument = strtok(buffer, " \n");
	av[0] = argument;

	i = 1;
	while (argument != NULL)
	{
		argument = strtok(NULL, " \n");
		av[i] = argument;
		i++;
	}

	av[i] = NULL;

	return (av);
}
/**
 * print_arrary - print array
 * @array: array
 * Return: 0.
 */
void print_arrary(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
	if (array[i] == NULL)
		printf("NULL\n");
}
