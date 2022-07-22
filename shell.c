#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **av;
char **make_av(char *);
void print_array(char **av);
int execute(char **command);

int main(void)
{
	char *buffer = NULL;
	char **command;
	size_t bufsize = 0;

	while(1)
	{
		printf("($) ");

		getline(&buffer, &bufsize, stdin);

		if (strcmp(buffer, "exit\n") == 0)
			break;
		else
		{
			command = make_av(buffer);
			if (execute(command == -1)
					break;
		}
	}
	free(buffer);
	free(av);

	return (0);
}
