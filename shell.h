#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int main(int ac, char **av);
char **str_tok(char *str);
char **av;
char **make_av(char *);
void print_array(char **av);
int execute(char **command);

#endif
