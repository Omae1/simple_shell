#include <stddef.h>
#include "shell.h"

/**
 * _strcpy - copies src str to dest str
 * @dest: points dest str where src will be copied
 * @src: points the src
 * Return: the starting address
 */
char *_strcpy(char *dest, const char *src)
{
char *dest_start = dest;
while (*src)
{
*dest++ = *src++;
}
*dest = '\0';
return (dest_start);
}

/**
 * _strlen - calc length of str
 * @str: points inpt str
 * Return: the leng of str
 */
size_t _strlen(const char *str)
{
const char *s = str;
while (*s)
{
s++;
}
return ((size_t)(s - str));
}

/**
 * _strcmp - cmp two str
 * @s1: points 1st str
 * @s2: points seconfd str
 * Return: 0 id str equal
 */
int _strcmp(const char *s1, const char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * custom_strcspn - calc length if initial segmment
 * @str: points input str
 * @reject: points rejecttb str
 * Return: char examined
 */
size_t custom_strcspn(const char *str, const char *reject)
{
const char *s1 = str;
size_t count = 0;
while (*s1)
{
const char *s2 = reject;
while (*s2)
{
if (*s1 == *s2)
{
return (count);
}
s2++;
}
s1++;
count++;
}
return (count);
}

/**
*_strcat - appends src string to destination string
*@dest: destination string
*@src: source string
*Return: appended string
*/
char *_strcat(char *dest, const char *src)
{
char *originalDest = dest;

while (*dest != '\0')
{
dest++;
}
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';

return (originalDest);
}
