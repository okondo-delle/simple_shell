#include "shell.h"

/**
 * _eputs - Prints a string to the standard error stream.
 * @str: The string to be printed.
 *
 * Return: None.
 */
void _eputs(char *str)
{
int a = 0;
if (!str)
return;
while (str[a] != '\0')
{
_eputchar(str[a]);
a++;
}
}

/**
 * _eputchar - Writes a character to the standard error stream.
 * @c: The character to be printed.
 *
 * Return: On success, returns 1.
 *         On error, returns -1 and sets the errno appropriately.
 */

int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putfd - Writes a character to the given file descriptor.
 * @c: The character to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: On success, returns 1.
 *         On error, returns -1 and sets the errno appropriately.
 */
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putsfd - Prints a string to the specified file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int _putsfd(char *str, int fd)
{
int i = 0;
if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
