#include "monty.h"

/**
 * getline_a - Read lines from a file and allocate memory for them
 * @file: The name of the file to read
 * 
 * Return: A dynamically allocated string containing the file contents
 * or NULL on failure
 */
char *getline_a(char *file)
{
	char *getline_string = NULL, *single_line = NULL;
	size_t size = 0;
	int file_fd;
	struct stat file_info;
	FILE *opened_file;

	/* Open the file for reading */
	file_fd = open(file, O_RDONLY);
	opened_file = fopen(file, "r");
	if (opened_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		close(file_fd);
		return (NULL);
	}

	/* Get the file size in bytes from fstat and allocate memory */
	fstat(file_fd, &file_info);
	getline_string = malloc(file_info.st_size + 1);
	if (!getline_string)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(opened_file);
		return (NULL);
	}

	/* Use getline() to read all lines into getline_string */
	getline_string[0] = '\0';
	while (getline(&single_line, &size, opened_file) != -1)
	{
		strcat(getline_string, single_line);
		free(single_line);
		single_line = NULL;
	}

	/* Clean the string of newline and '$' characters */
	string_clean(getline_string);

	/* Clean up and close the file */
	close(file_fd);
	fclose(opened_file);

	free(single_line);
	return (getline_string);
}

/**
 * string_clean - Clean a string of newline and '$' characters
 * @getline_string: The string to clean
 * 
 * Return: The cleaned string
 */
char *string_clean(char *getline_string)
{
	int i;

	for (i = 0; getline_string[i]; i++)
	{
		if (getline_string[i] == '\n' || getline_string[i] == '$')
			getline_string[i] = ' ';
	}

	return (getline_string);
}
