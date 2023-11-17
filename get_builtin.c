#include "main.h"
/**
 *is_builtin-run a command if it is builtin
 *@s:command
 *Return:0 if successful, -1 otherwise
 */
int is_builtin(char *s)
{
	builtin cmd[] = {
		{"env", env},
		{"exit", custom_exit},
		{NULL, NULL}
	};
	int i, check;

	i = 0;
	while (cmd[i].command != NULL)
	{
		check = s_cmd_compare(cmd[i].command, s);
		if (check == 0)
		{
			cmd[i].function();
			return (0);
		}
		i++;
	}
	return (-1);
}
/**
 *s_cmd_compare- compares the command passed to shell and the list of builtins
 *@s: terminal string
 *@cmd: builtin command
 *Return:0 if htey match or -1
 */
int s_cmd_compare(char *cmd, char *s)
{
	int j, match = -1;

	if (strlen(cmd) != strlen(s))
		return (-1);
	j = 0;
	while (cmd[j] != '\0' && s[j] != '\0')
	{
		if (cmd[j] == s[j])
		{
			match = 0;
			j++;
		}
		else
		{
			break;
		}
	}

	return (match);
}
