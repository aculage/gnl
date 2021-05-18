#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//adds content of a char buffer to string str, resizing str
char	*ft_stradd(char *str, char *buffer, int new_buf_size)
{
	char	*ret;
	int		ptr;
	int		slen;

	ptr = 0;
	slen = 0;
	if (str)
		slen = ft_strlen(str);
	ret = malloc(slen + new_buf_size + 1);
	if (!ret)
		return (NULL);
	while (ptr < slen)
	{
		ret[ptr] = str[ptr];
		ptr++;
	}
	ptr = 0;
	while (ptr < new_buf_size)
	{
		ret[slen + ptr] = buffer[ptr];
		ptr++;
	}
	ret[slen + new_buf_size] = 0;
	free(str);
	return (ret);
}

//this function shifts current position in a buffer to a new endline
void	shift_ptr(t_buffer *c_buf)
{
	while (c_buf->curr_pos < c_buf->buf_size
		&& c_buf->buffer[c_buf->curr_pos] != '\n')
		c_buf->curr_pos++;
	return ;
}

//this function reads a new buffer with certain precautions
void	buf_readify(t_buffer *c_buf)
{
	c_buf->curr_pos = 0;
	c_buf->prev_pos = 0;
	c_buf->buf_size = read(c_buf->fd, c_buf->buffer, BUFFER_SIZE);
	return ;
}

//this function creates a string from a static buffer.
//and also reads from corresponding fd into buffer
char	*create_str(t_buffer *c_buf)
{
	char	*ret;

	ret = malloc(1);
	if (!ret)
		return (NULL);
	*ret = 0;
	if (c_buf->buf_size == -2)
		buf_readify(c_buf);
	while (c_buf->buf_size > 0)
	{
		shift_ptr(c_buf);
		ret = ft_stradd(ret, c_buf->buffer + c_buf->prev_pos,
				c_buf->curr_pos - c_buf->prev_pos);
		if (!ret)
			return (NULL);
		if (c_buf->curr_pos == c_buf->buf_size)
			buf_readify(c_buf);
		else
		{
			c_buf->prev_pos = ++c_buf->curr_pos;
			return (ret);
		}
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*lst = NULL;
	t_buffer		*current_buffer;

	current_buffer = ft_getbyfd(&lst, fd);
	if (!current_buffer)
		return (-1);
	*line = create_str(current_buffer);
	if (current_buffer->buf_size == 0)
	{
		ft_rmlstelem(&lst, current_buffer);
		return (0);
	}
	if (current_buffer->buf_size == -1)
	{
		ft_rmlstelem(&lst, current_buffer);
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (!(*line))
	{
		ft_rmlstelem(&lst, current_buffer);
		return (-1);
	}
	return (1);
}
