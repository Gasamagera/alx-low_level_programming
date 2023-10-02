#include "main.h"

/**
 * create_file - function that Creates a file.
 *
 * @filename: A pointer to the name of the created file.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: -1 if the function fails. otherwise 1.
 */

int create_file(const char *filename, char *text_content)

{
	int op, writ, n = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (n = 0; text_content[n];)
			n++;
	}

	op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	writ = write(op, text_content, n);

	if (op == -1 || writ == -1)
		return (-1);

	close(op);

	return (1);
}
