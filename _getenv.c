#include "main.h"
/**
  *env_value-pushes pointer to beginning of environment value
  *@env_var: var=value string
  *Return:pointer to the value in theenvironment, or NULL if there is no match
  */
char *env_value(char *env_var)
{

	if (env_var == NULL)
		return (NULL);
	while (*env_var != '=')
		env_var++;
	env_var++;
	return (env_var);

}
/**
  *_getenv- gets an environment variable
  *@name:environment variable
  *Return:pointer to the value in theenvironment, or NULL if there is no match
  */
char *_getenv(const char *name)
{
	int i, j;
	unsigned int found = 0;
	char *temp;

	if (name == NULL || *name == '\0')
		return (NULL);
	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0' && name[j] != '\0')
		{
			if (environ[i][j] == name[j])
			{
				found = 1;
				j++;
			}
			else
			{
				found = 0;
				break;
			}
		}
		if (found == 1 && environ[i][j] == '=')/*ensure it's varname*/
		{
			temp = environ[i];
			break;
		}
		i++;
	}
	if (found == 0)
		return (NULL);
	return (env_value(temp));
}

