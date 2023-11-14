#include "main.h"

void line_interpreter(void);
/**
*line_interpreter - takes command as inputs and translates
*Return: Nothing
*/
void line_interpreter(void)
{
	while (1)
	{
		write(STDOUT_FILENO, "#simpleShell > ", sizeof("#simpleShell > "));
		fflush(stdout);

		size_t input_size = 0;
		ssize_t input_length;
		char *input = NULL;

		input_length = getline(&input, &input_size, stdin);
		if (input_length < 0)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO,  "\nExiting shell.\n ",
				sizeof("\nExiting shell.\n "));
				free(input);
				break;
			}
			else
			{
				perror("Error reading input");
				free(input);
				_exit(EXIT_FAILURE);
			}
		}
	if (input_length > 0 && input[input_length - 1] == '\n')
		input[input_length - 1] = '\0';

	char *args[2];

	args[0] = input;
	args[1] = NULL;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(input);
		_exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(input, args, environ) == -1)
		{
			write(STDERR_FILENO, input, _strlen(input));
			write(STDERR_FILENO, ": No such file or directory\n",
			sizeof(": No such file or directory\n") - 1);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
	free(input);
	}
}
