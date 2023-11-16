#include "main.h"
/**
 *find_file_path-looks for files in the current PATH
 *@file_name:command name
 *Return:malloc'd file_path or NULL
 */
char *find_file_path(char *file_name)
{
	int exist;
	char *path_copy, *file_path = NULL, *path;

	if (file_name == NULL)
		return (NULL);

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	file_path = search_path(file_path, path_copy, file_name);
	if (file_path != NULL)
		return (file_path);

	/*check if filename is a valid path*/
	exist = access(file_name, F_OK);
	if (exist == 0)
	{
		free(file_path);
		free(path_copy);
		return (strdup(file_name));
	}
	free(path_copy);
	free(file_path);
	return (NULL);
}
/**
*search_path-look for file in PATH directories
*@file_path:file_path
*@path_copy:PATH duplicate(using MALLOC)
*@file_name:file_name
*Return: final path if found or NULL
*/
char *search_path(char *file_path, char *path_copy, char *file_name)
{
	char *dir_path;
	int file_len = strlen(file_name), exist;

	dir_path = strtok(path_copy, ":");
	while (dir_path != NULL)
	{
		free(file_path);
		file_path = calloc(sizeof(char), (strlen(dir_path) +
file_len + 2));/*2 = / and null byte*/
		if (file_path == NULL)
			return (NULL);
		strcat(file_path, dir_path);
		strcat(file_path, "/");
		strcat(file_path, file_name);
		exist = access(file_path, F_OK);
		if (exist == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			dir_path = strtok(NULL, ":");
		}
	}
	free(file_path);
	return (NULL);
}
