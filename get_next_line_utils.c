#include "get_next_line.h"


t_list	*ft_lstnew(void *content)
{
	t_list *ret;
	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

void	ft_rmlstelem( t_list *list, t_buffer *current_buffer)
{
	t_list	*to_del;

	if (!list)
		return ;
	while ((t_buffer *)(list->next->content) != current_buffer || list ->next != NULL)
	{
		list = list->next;
	}
	if (list -> next != NULL)
	{
		to_del = list->next;
		list->next = list->next->next;
		free(to_del->content);
		free(to_del);
	}
	return ;
}

t_buffer	*ft_getbyfd(t_list **lst, int fd)
{
	t_buffer	*newbuf;
	t_list		*lcl;

	newbuf = malloc(sizeof(t_buffer));
	if (!newbuf)
		return(newbuf);
	newbuf->buf_size = -2;
	newbuf->fd = fd;
	newbuf->eof = false;
	newbuf->prev_pos = 0;
	newbuf->curr_pos = 0;
	if (*lst)
	{
		lcl = *lst;
		while (((t_buffer *)(lcl)->content)->fd != fd)
		{
			if (!((lcl)->next))
			{
				lcl->next = ft_lstnew(newbuf);
				return (newbuf);
			}	
			lcl = lcl->next;
		}
	}
	else
	{
		*lst = ft_lstnew(newbuf);
		return(newbuf);
	}
	return (lcl->content);
}

int     ft_strlen(const char *str)
{
        int     cnt;

        cnt = 0;
        while (*(str + cnt) != 0)
        {
                cnt++;
        }
        return (cnt);
}
