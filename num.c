#include "shell.h"

void line_interpreter(void);
/**
*line_interpreter - takes command as inputs and translates
Return: Nothing
*/
void line_interpreter(void)
{
	size_t input_size = 0;
	char *args[2];
	pid_t child_pid = fork();
	ssize_t input_length;
	char *input = NULL;
	
	while (1)
	{
		write(STDOUT_FILENO, "#simpleShell > ", sizeof("#simpleShell > ") - 1);
		fflush(stdout);


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


	args[0] = input;
	args[1] = NULL;

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
