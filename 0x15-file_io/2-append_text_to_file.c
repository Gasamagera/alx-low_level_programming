#include "main.h"

/**
 * append_text_to_file - function that will append text at the of file.
 *
 * @filename: A pointer to the name of the appended file.
 * @text_content: A string to be added to the file.
 *
 * Return: -1 if the function fails. otherwise 1.
 */

int append_text_to_file(const char *filename, char *text_content)

{
	int op, writ, n = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (n = 0; text_content[n];)
			n++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	writ = write(op, text_content, n);

	if (op == -1 || writ == -1)
		return (-1);

	close(op);

	return (1);
}
