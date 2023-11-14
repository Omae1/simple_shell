#include "main.h"

void custom_perror(const char *msg);
/**
 * custom_perror - handle err function to stderr
 * @msg: points to null terminattedd str
 */
void custom_perror(const char *msg)
{
write(STDERR_FILENO, msg, _strlen(msg));
write(STDERR_FILENO, "\n", 1);
}
/**
 * custom_tokenize - tokenizes inp str to arrayy of arg
 * @args: stores tokenized arg
 * @max_args: maximum no of arg to stoore
 * @input: str to be tokenized
 * Return: no of arg
 */
int custom_tokenize(char *input, char *args[], int max_args)
{
int num_args = 0;
char *token = strtok(input, " ");
while (token != NULL && num_args < max_args - 1)
{
args[num_args] = token;
num_args++;
token = strtok(NULL, " ");
}
args[num_args] = NULL;
return (num_args);
}
/**
 * isExecutable - checs speciified file path of its execuatablle
 * @path: checs executabilityy
 * Return: 1
 */
int isExecutable(const char *path)
{
if (access(path, X_OK) == 0)
{
return (1);
}
return (0);
}
/**
 * customShell - allows userr enterr & execut cmds
 * @argc: no of arg
 * @argv: cmd line arg
 * Return: interger representedd
 */
int customShell(int argc, char *argv[])
{
char input[MAX_INPUT_SIZE];
char *args[MAX_ARGS];
int num_args;
while (1)
{
write(STDOUT_FILENO, "simpleshell > ", _strlen("simpleshell > "));
int input_size = read(STDIN_FILENO, input, MAX_INPUT_SIZE);
if (input_size < 0)
{
custom_perror("Read error");
break;
}
if (input_size == 0)
{
break;
}
input[input_size - 1] = '\0';
num_args = custom_tokenize(input, args, MAX_ARGS);
if (num_args > 0)
{
if (_strcmp(args[0], "exit") == 0)
{
break;
}
pid_t pid = fork();
if (pid < 0)
{
custom_perror("Fork failed");
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
custom_perror("Execution error");
exit(EXIT_FAILURE);
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
