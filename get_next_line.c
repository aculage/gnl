#include "get_next_line.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
//Locates endline in a char buffer
//
int	locate_endl(char *input, bool eof, int bufsize)
{
	int cnt;

	while (cnt < bufsize)
	{
		if (input[cnt] == '\n' || input[cnt] == '\r')
			return(cnt);
	}
	if (eof)
		return (cnt);
	return (-1);
}



//Gets next line from file. Leaves rest of the buffer in the list with key = fd
char	*ft_getline(int fd, int *status)
{
	char			*ret;
	static char		buffer[BUFFER_SIZE];
	bool			eof;
	static int		bufsize = 0;
	int				pos;


	/*if (bufsize != 0)
	{
		pos = locate_endl(&buffer, false, bufsize);
		if (pos != -1)
			//realloc
		else 
		{
			
		}

	}*/
	if (bufsize == 0)
	{	
		bufsize = read(fd, buffer, BUFFER_SIZE);
		pos = locate_endl(buffer, false, bufsize);
		if (pos != -1)
		{
			ret = malloc(pos + 1);
			ft_memmove(ret, buffer, pos);
			*status = 1;
			ft_memmove(buffer, buffer + pos + 1, bufsize - pos - 1);
			bufsize = bufsize - pos - 1;
		}
		return(ret);
	}
	return (NULL);
}

int get_next_line(int fd, char **line)
{
	int status;

	*line = ft_getline(fd, &status);
	return(status);	
}