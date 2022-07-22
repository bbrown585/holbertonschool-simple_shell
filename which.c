#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	const char *path = getenv("PATH");

	if (!path)
	{
		printf("getenv failed\n");
		return (-1);
	}
	
	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
			printf(" NOT FOUND\n");
		i++;
	}
	return (0);
}
