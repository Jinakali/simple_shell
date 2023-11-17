#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
/**
 *struct list_path-singly linked list
 *@data: string-(malloced)
 *@next: points to the next node
 *
 *Description: singly linked list node structure of PATH
 */
typedef struct list_path
{
	char *data;
	struct list_path *next;
} list_p;

extern char **environ;
void free_dup(char *dup1, char *dup2);
int token_count(char *s, char *delim);
char **str_2words(char *s, char *delim);
char *_getenv(const char *name);
char *env_value(char *env_var);
void print_path(void);
void free_arr(char **arr);
void free_list(list_p *head);
list_p *add_node_end(list_p **head, char *path);
list_p *create_path_list(void);
int _setenv(const char *name, const char *value, int overwrite);
void error_msg(void);
char *search_path(char *file_path, char *path_copy, char *file_name);
char *find_file_path(char *file_name);
int is_blank(char *lineptr);
void command_execution(char **command, char *file_path, char *lineptr);
char *is_file_path(char **command, char *file_path, char *lineptr);
char **input_tokenisation(char **command, char *file_path, char *lineptr);
#endif/*main.h*/
