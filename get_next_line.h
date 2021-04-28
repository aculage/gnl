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

//Gets next line from a file. 
//A line is a charstring that ends with \n.
int get_next_line(int fd, char **line);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstnew(void *content);
void ft_lstdelone(t_list *lst, void (*del)(void*));

#endif