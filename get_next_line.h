#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>

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
	char			*buffer;
	int				buf_size;
}					t_buffer;


//Gets next line from a file. 
//A line is a charstring that ends with \n.
int get_next_line(int fd, char **line);

//Finds a list node which contains corresponding buffer for fd
t_list	*ft_fndbyfd(t_list *lst, int fd);
void	*ft_memmove(void *dest, const void *src, size_t count);
#endif