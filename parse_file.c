#include "monty.h"

/**
 * parse_file - reads the file and retrieves the opcodes
 * @file: name of the file
 */
void parse_file(char *file)
{
	int fd, nb_line, pos = 0, sz_buff = 1024;
	char *line = NULL, *opcode, *buff;
	ssize_t sz;


	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	buff = malloc(sizeof(char) * sz_buff);
	sz = read(fd, buff, sz_buff);
	buff[sz] = '\0';

	for (nb_line = 0; my_getline(&line, &pos, &buff) != -1; nb_line++)
	{
		opcode = strtok(line, DELIMS);
		if (opcode)
			match_opcode(opcode, nb_line + 1, buff);
	}
	free(buff);
}
