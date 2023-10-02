#include "main.h"

/**
 * read_textfile- Read text file print to the standard output.
 *
 * @filename: text file to be red.
 * @letters: number of letters wil be red.
 *
 * Return: 0 if filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)

{
	ssize_t one;
	ssize_t two;
	ssize_t three;

	char *nameMe;

	if (filename == NULL)
		return (0);

	nameMe = malloc(sizeof(char) * letters);

	if (nameMe == NULL)
		return (0);

	one = open(filename, O_RDONLY);
	two = read(one, nameMe, letters);
	three = write(STDOUT_FILENO, nameMe, two);

	if (one == -1 || two == -1 || three != two || three == -1)
	{
		free(nameMe);

		return (0);
	}

	free(nameMe);

	close(one);

	return (three);
}
