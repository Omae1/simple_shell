#include "main.h"

/**
*exit_shell - exits from the prompt
*Return: Nothing
*/
void exit_shell(void)
{
	write(STDOUT_FILENO, "Exiting the shell.\n",
	sizeof("Exiting the shell.\n") - 1);
	exit(0);
}



