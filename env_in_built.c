#include "main.h"

void myShell(void);
/**
 * myShell - implements a custom shell
 * Return: desci of the return  value
 */
void myShell(void)
{
char input[MAX_INPUT_SIZE];
int inputIndex = 0;
write(STDOUT_FILENO, "SimpleShell > ", sizeof("SimpleShell > "));
fflush(stdout);
while (1)
{
char c;
if (read(STDIN_FILENO, &c, 1) != 1)
{
perror("Read error");
exit(EXIT_FAILURE);
}
if (c == '\n')
{
input[inputIndex] = '\0';
break;
}
input[inputIndex] = c;
inputIndex++;
if (inputIndex >= MAX_INPUT_SIZE - 1)
{
perror("Input too long");
break;
}
}
if (_strcmp(input, "exit") == 0)
{
}
else if (_strcmp(input, "env") == 0)
{
char **env = environ;
while (*env != NULL)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
}
else
{
pid_t pid = fork();
if (pid < 0)
{
perror("Fork failed");
}
else if (pid == 0)
{
if (execlp(input, input, (char *)NULL) == -1)
{
perror("Execution error");
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

