#include "main.h"

/**
 *main-run commands with their full path, without any argument.
 *Return: 0 always
 *Description:
 */
int main(void)
{
	pid_t child_pid;
	int wstatus, length;
	char **command, *delim = " ", *lineptr = NULL;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		printf("($) ");
	while ((getline(&lineptr, &n, stdin)) != EOF)
	{
		length = strlen(lineptr);
		lineptr[length - 1] = '\0';/*remove enter (== /n) character*/
		command = str_2words(lineptr, delim);
		if (command == NULL)
			error_msg();
		child_pid = fork();
		if (child_pid == -1)
			error_msg();
		if (child_pid == 0)
		{
			if ((execve(command[0], command, environ)) == -1)
				error_msg();

		}
		else
		{
			wait(&wstatus);
		}
		if (isatty(STDIN_FILENO))
			printf("($) ");
		free_arr(command);
	}
	if (isatty(STDIN_FILENO))
		putchar('\n');
	free(lineptr);
	return (0);
}
/**
 *error_msg-print error message strating with .hsh
 */
void error_msg(void)
{
	perror("./hsh");
	exit(EXIT_FAILURE);
}
