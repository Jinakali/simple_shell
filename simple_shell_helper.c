#include "main.h"
/**
 *input_tokenisation-splits input into tokens
 *@command:2d array that holds tokenised input
 *@file_path:location of command in path
 *@lineptr:input
 *Return: 2darray or exit
 */
char **input_tokenisation(char **command, char *file_path, char *lineptr)
{
	char *delim = " ";

	(void) file_path;

	command = str_2words(lineptr, delim);
	if (command == NULL)
	{
		free(lineptr);
		error_msg();
	}
	return (command);
}
/**
 *is_file_path-finds location of command in path
 *@command:2d array that holds tokenised input
 *@file_path:location of command in path
 *@lineptr:input
 *Return:file_path or exit
 */
char *is_file_path(char **command, char *file_path, char *lineptr)
{
	file_path = find_file_path(command[0]);
	if (file_path == NULL)
	{
		free_arr(command);
		free(lineptr);
		error_msg();
	}

	return (file_path);
}
/**
 *command_execution-runs command
 *@command:2d array that holds tokenised input
 *@file_path:location of command in path
 *@lineptr:input
 */
void command_execution(char **command, char *file_path, char *lineptr)
{
	pid_t child_pid;
	int wstatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		free_arr(command);
		free(file_path);
		free(lineptr);
		error_msg();
	}
	if (child_pid == 0)
	{
		if ((execve(file_path, command, environ)) == -1)
		{
			free(lineptr);
			free_arr(command);
			error_msg();
		}
	}
	else
	{
		wait(&wstatus);
	}
}
