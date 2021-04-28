#include "get_next_line.h"
#include <stdio.h>

//Gets next line from file. Leaves rest of the buffer in the list with key = fd
char	*getline(int fd)
{
	char	*buffer;
	int		capacity;

	capacity = BUFFER_SIZE;
	buffer = malloc(capacity);
	if (!buffer)
		return(NULL);
	read(fd, buffer, capacity);
	

}

int get_next_line(int fd, char **line)
{
	return();
}