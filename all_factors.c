#include <stdlib.h>
#include "rsa.h"

/**
 * main - Reads a file and converts the contents each of the lines read
 * to an integer and prints the 2 factors of the number
 * that the product is same as the number read from the given file.
 * @ac: argument count.
 * @argv: the argument passed in the CLI.
 *
 * Return: Always zero (on success).
 */

int main(int ac, char *argv[])
{
	FILE *fd;
	char *line = NULL, *endptr;
	unsigned long long int number;
	size_t size = 0;
	int line_number = 0, len_line;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: factors\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "could not open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fd) != -1)
	{
		line_number++;
		len_line = strlen(line);
		if (line == NULL)
		{
			fprintf(stderr, "L<%d>: unknown instruction <%s>", line_number, line);
			exit (EXIT_FAILURE);
		}
		number = strtoul(line, &endptr, 10);
		print_product(number);
	}
	return (EXIT_SUCCESS);
}
