#include "main.h"

/**
 *main-run commands with their full path, without any argument.
 *Return: 0 always
 *Description:
 */
int main(void)
{
	int length, check;
	char **command, *lineptr = NULL, *file_path;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		printf("($) ");
	while ((getline(&lineptr, &n, stdin)) != EOF)
	{
		length = strlen(lineptr);
		lineptr[length - 1] = '\0';/*remove enter (== /n) character*/
		check = is_blank(lineptr);
		if (check == 0)
		{
			command = input_tokenisation(command, file_path, lineptr);
			file_path = is_file_path(command, file_path, lineptr);
			command_execution(command, file_path, lineptr);
			if (isatty(STDIN_FILENO))
				printf("($) ");
			free_arr(command);
			free(file_path);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				printf("($) ");
		}
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
/**
 *is_blank-check whether input is etirely composed of blank lines
 *@lineptr:input
 *Return: 0 if other characters present
 */
int is_blank(char *lineptr)
{
	int i = 0;

	if (lineptr == NULL)
		return (-1);
	while (lineptr[i] != '\0')
	{
		if (lineptr[i] != ' ')
			return (0);
		i++;
	}
	return (-1);
}
