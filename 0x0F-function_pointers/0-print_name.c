/**
 * print_name - prints a name
 * @name: name to be printed
 * @f: function to use to print the name
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
