#include <stdio.h>
#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of command-line arguments
* @argv: array of strings represnting command-1
* Return: 0 on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	char *currentline;
	FILE *montyfile;
	size_t buffersize = 0;
	ssize_t bytesread = 1;
	stack_t *stack = NULL;
	unsigned int linenumber = 0;

	/* check for correct number of command-line arguments*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*open the monty file for reading*/
	montyfile = fopen(argv[1], "r");
	bus.montyfile = montyfile;
	if (!montyfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*read and execute monty code line by line*/
	while (bytesread > 0)
	{
		currentline = NULL;
		bytesread = getline(&currentline, &buffersize, montyfile);
		bus.currentline = currentline;
		linenumber++;
		if (bytesread > 0)
		{
			execute(currentline, &stack, linenumber, montyfile);
		}
		free(currentline);
	}
	/* clean up and close the file*/
	free_stack(stack);
	fclose(montyfile);
return (0);
}
