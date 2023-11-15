#include "shell.h"

int lineInterpreter(int argc __attribute__((unused)), char *argv[] __attribute__((unused)));
/**
*writeError- handles file related errors
*@filename: the string to be copied
*/

void writeError(const char *filename)
{
	const char *noSuchFileMessage = ": No such file or directory\n";
	size_t errorMessageLength = _strlen(filename) + _strlen(noSuchFileMessage);
	char *errorMessage = malloc(errorMessageLength + 1);

	if (errorMessage == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	_strcpy(errorMessage, filename);
	_strcat(errorMessage, noSuchFileMessage);
	write(STDERR_FILENO, errorMessage, errorMessageLength);

	free(errorMessage);
}

/**
*lineInterpreter - prompes user for input
*@argc: thee number of arguments
*@argv: array of strings
*Return: 0 (success)
*/
int lineInterpreter(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];
	ssize_t input_size;
	int num_args = 0;
	char *token = strtok(input, " ");

	while (1)
	{
	char prompt[] = "simpleShell > ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	fflush(stdout);


	input_size = read(STDIN_FILENO, input, sizeof(input));
	if (input_size <= 0)
	{
		break;
	}
	input[input_size - 1] = '\0';


	while (token != NULL && num_args < MAX_ARGS - 1)
	{
		args[num_args] = token;
		num_args++;
		token = strtok(NULL, " ");
	}
	args[num_args] = NULL;

	if (num_args > 0)
	{
		pid_t pid = fork();

		if (pid < 0)
			perror("Fork failed");
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				writeError(args[0]);
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}
}
return (0);
}
