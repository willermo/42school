#include "get_next_line.h"

static char	*update_line(char *line, int line_pos, int max_pos)
{
	char *tmp_line;

	tmp_line = (char *)malloc(sizeof(char) * (line_pos + max_pos + 1));
	if (line)
	{
		for (int i = 0; i < line_pos; i++)
			tmp_line[i] = line[i];
		free(line);
	}
	return (tmp_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_pos = -1;
	static int	max_buffer_pos;
	int		line_pos = 0;
	char		*line = NULL;

	// check input
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= 1024)
		return (NULL);

	// initialize buffer on first run or updates it on buffer end
	if (buffer_pos == -1 || buffer_pos == max_buffer_pos)
	{
		max_buffer_pos = read(fd, &buffer, BUFFER_SIZE);
		buffer_pos = 0;
	}

	// returns NULL on read error
	if (max_buffer_pos < 1)
		return (NULL);

	// initial allocation for line to be returned
	line = update_line(line, line_pos, max_buffer_pos);

	// cycle along buffer
	while (buffer_pos < max_buffer_pos)
	{
		line[line_pos++] = buffer[buffer_pos++];

		//exits cycle on newline
		if (line[line_pos - 1] == '\n')
			break;

		// updates buffer and line
		if (buffer_pos == max_buffer_pos)
		{
			max_buffer_pos = read(fd, &buffer, BUFFER_SIZE);
			buffer_pos = 0;
			line = update_line(line, line_pos, max_buffer_pos);
		}
	}
	line[line_pos] = 0;
	return (line);
}
