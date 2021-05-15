#include "get_next_line.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//adds content of a char buffer to string str, resizing str
char	*ft_stradd(char *str, char *buffer, int new_buf_size)
{
	char	*ret;
	int		ptr;

	ptr = 0;
	ret = malloc(ft_strlen(str) + new_buf_size + 1);
	if (!ret)
		return (NULL);
	while (ptr < ft_strlen(str))
	{
		ret[ptr] = str[ptr];
		ptr++;
	}
	ptr = 0;
	while (ptr < new_buf_size)
	{
		ret[ft_strlen(str) + ptr] = buffer[ptr];
		ptr++;
	}
	ret[ft_strlen(str) + new_buf_size] = 0;
	free(str);
	return (ret);
}

//this function creates a string from a static buffer.
//and also reads from corresponding fd into buffer
char	*create_str(t_buffer *c_buf)
{
	char	*ret;

	ret = malloc(1);
	if (!ret)
		return(NULL);
	*ret = 0;
	if (c_buf->buf_size == -2)
	{
		c_buf->buf_size = read(c_buf->fd, c_buf->buffer, BUFFER_SIZE);
		c_buf->curr_pos = 0;
	}
	while (c_buf->buf_size > 0)
	{
		while(c_buf->curr_pos < c_buf->buf_size && c_buf->buffer[c_buf->curr_pos] != '\n')
			c_buf->curr_pos++; //check for endline 
		//locating endline or figuring out there is no endl
		ret = ft_stradd(ret, c_buf->buffer + c_buf->prev_pos, c_buf->curr_pos - c_buf->prev_pos);
		if (!ret)
			return(NULL);
		if (c_buf->curr_pos == c_buf->buf_size)
		{
			c_buf->curr_pos = 0;
			c_buf->prev_pos = 0;
			c_buf->buf_size = read(c_buf->fd, c_buf->buffer, BUFFER_SIZE);
		}
		else
		{
			(c_buf->curr_pos)++;
			c_buf->prev_pos = c_buf->curr_pos;
			return(ret);
		}
	}
	return(ret);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*lst = NULL; 
	t_buffer		*current_buffer; // current buffer struct pointer

	current_buffer = ft_getbyfd(&lst, fd);
	if (!current_buffer)
		return (-1);
	*line = create_str(current_buffer);
	if (current_buffer->buf_size == 0)
	{
		//ft_rmlstelem(current_buffer);
		return (0);
	}
	if (current_buffer->buf_size == -1 || !(*line))
	{
		*line = NULL;
		return (-1);
	}
	return (1);
}