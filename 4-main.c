#include "main.h"
int main()
{
	char input[MAX_INPUT_SIZE];
	ssize_t bytesRead = read(STDIN_FILENO, input, sizeof(input));

	while (1)
	{
		write(STDOUT_FILENO, "Shell> ", sizeof("Shell> ") - 1);

		if (bytesRead == -1)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	
	if (bytesRead == 0)
	{
		break;
	}

	input[bytesRead -1] = '\0';

	if (_strlen(input) == 0)
	{
		continue;
	}
	if (_strcmp(input, "exit") == 0)
	{
		break;
	}
	else
	{
		write(STDOUT_FILENO, "Command not found: ", sizeof("Command not found: ") - 1);
		write(STDOUT_FILENO, input, _strlen(input));
		write(STDOUT_FILENO, "\n", sizeof("\n") - 1);
	}
}
return (0);
}
