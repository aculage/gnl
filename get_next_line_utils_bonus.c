#include "get_next_line_bonus.h"


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

void	ft_rmlstelem( t_list **list, t_buffer *current_buffer)
{
	t_list	*to_del;
	t_list	*curr;

	if (!list)
		return ;
	to_del = NULL;
	if ((t_buffer *)((*list)->content) == current_buffer)
	{
		to_del = *list;
		*list = (*list)->next;
	}
	else
	{
		curr = *list;
		while (curr->next != NULL)
		{
			if((t_buffer *)(curr->next->content) == current_buffer)
				break ;
			curr = curr->next;
		}
		if (curr -> next != NULL)
		{
			to_del = curr->next;
			curr->next = curr->next->next;
		}
	}
	if (to_del)
	{
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
	free(newbuf);
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
