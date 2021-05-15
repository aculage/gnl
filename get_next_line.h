#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct		s_list
{
	void			*content;
	struct s_list   *next;
}					t_list;

typedef struct		s_buffer
{
	int				fd;
	int				prev_pos;
	char			buffer[BUFFER_SIZE];
	int				buf_size;
	int				curr_pos;
	bool			eof;
}					t_buffer;

//gcc -Werror -Wall -Wextra -g  get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=32 -I /. -o gl

//Gets next line from a file. 
//A line is a charstring that ends with \n.
int 		get_next_line(int fd, char **line);

//Finds a list node which contains corresponding buffer for fd
//If a list node is nonexistent - creates a new node with empty buffer
t_buffer	*ft_getbyfd(t_list **lst, int fd);
//DEPRECATE?
void		*ft_memmove(void *dest, const void *src, size_t count);
int     	ft_strlen(const char *str);
#endif