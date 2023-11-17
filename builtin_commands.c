#include "main.h"
/**
 *custom_exit-leave shell
 */
void custom_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 *env-print environment
 */
void env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
