#include "main.h"

/**
 * create_buffer - function that llocates 1024 bytes for a buffer.
 *
 * @file: The name of the file that stored by buffer for charactars.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)

{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}


/**
 * close_file - Closes file descriptors.
 *
 * @op: The file descriptor that should be closed.
 *
 */


void close_file(int op)

{
	int a;

	a = close(op);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", op);
		exit(100);
	}
}



/**
 * main - Copies the contents of a file to another.
 *
 * @argc: The number of arguments sent to the program.
 * @argv: pointer Array to the arguments.
 *
 * Return: 0 if true.
 *
 * Description: If the argument count is false - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */


int main(int argc, char *argv[])
{
	int from, to, re, writ;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	re = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || re == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		writ = write(to, buffer, re);
		if (to == -1 || writ == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		re = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (re > 0);

	free(buffer);
	close_file(from);
	close_file(to);
	return (0);

