#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 128
#include <stddef.h>
#include <stdarg.h>

void myShell(void);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
size_t custom_strcspn(const char *str, const char *reject);
int customShell(int argc, char *argv[]);
void custom_perror(const char *msg);
int custom_tokenize(char *input, char *args[], int max_args);
int isExecutable(const char *path);
int customshell(int argc, char *argv[]);
int custom_tokenize(char *input, char *args[], int max_args);
extern char **environ;

char *_strchr(char *s, char c);
void line_interpreter(void);
int lineInterpreter(int argc __attribute__((unused)), char *argv[] __attribute__((unused)));
void exit_shell(void);
void writeError(const char *filename);
char *_strcat(char *dest, const char *src);

#endif
