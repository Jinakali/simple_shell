#include "main.h"
/**
 *free_dup-free duplicated strings from tokenising function
 *@dup1:duplicate string
 *@dup2:duplicate string
 */
void free_dup(char *dup1, char *dup2)
{
	free(dup1);
	free(dup2);
}
/**
 *str_2words-tokenises a string
 *@s: string
 *@delim: delimetre
 *Return:array of each word of the string
 */
char **str_2words(char *s, char *delim)
{
	int arr_size, i;
	char **arr, *str_dup, *str_dup1, *token;

	if (s == NULL || delim == NULL)
		return (NULL);
	str_dup = strdup(s);
	str_dup1 = strdup(s);
	if (str_dup == NULL || str_dup1 == NULL)
	{
		free_dup(str_dup1, str_dup);
		return (NULL);
	}
	arr_size = token_count(str_dup, delim);
	if (arr_size == -1)
	{
		free_dup(str_dup1, str_dup);
		return (NULL);
	}
	arr = malloc(sizeof(char *) * (arr_size + 1));
	if (arr == NULL)
	{
		free_dup(str_dup1, str_dup);
		return (NULL);
	}
	i = 0;
	token = strtok(str_dup1, delim);
	while (token != NULL)
	{
		arr[i] = strdup(token);
		if (arr[i] == NULL)
		{
			free_dup(str_dup1, str_dup);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
	}
	arr[i] = NULL;
	free_dup(str_dup1, str_dup);
	return (arr);
}
/**
 *token_count-count no of tokens generated
 *@s:string
 *@delim:delimetre
 *Return:no of tokens generated
 */
int token_count(char *s, char *delim)
{
	int i;

	if (s == NULL || delim == NULL)
		return (-1);

	i = 0;
	if (strtok(s, delim) != NULL)
		i++;
	else
		return (-1);
	while (strtok(NULL, delim) != NULL)
		i++;
	return (i);
}

/**
 *free_arr - frees a 2d array and its elements
 *@arr:2darray
 */
void free_arr(char **arr)
{
	int i;

	if (arr == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

