#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

//sets to first arg pointer to PREVIOUS element of the one to be found
//this is to easily remove one
//if list is empty or you pass a NULL, func return is false, *elem is NULL
//if element is located in the HEAD of the list, HEAD is set instead
//if element is not located, func return is false, but *elem is last element
//it is up to you to check for it
bool	ft_lstlocate(t_list **elem, t_list *list, int fd)
{
	*elem = NULL;
	if (!list)
		return (false);
	if (((t_buffer *)(list->content))->fd != fd)
	{
		if (!(list->next))
		{
			*elem = list;
			return (false);
		}
		while (((t_buffer *)(list->next->content))->fd != fd)
		{
			list = list->next;
			if (!(list->next))
			{
				*elem = list;
				return (false);
			}
		}
	}
	*elem = list;
	return (true);
}

void	ft_rmlstelem(t_list **list, t_buffer *current_buffer)
{
	t_list	*to_del;
	t_list	*curr;

	if (!list)
		return ;
	if (ft_lstlocate(&curr, *list, current_buffer->fd))
	{
		if (curr->content == current_buffer)
		{
			*list = (*list)->next;
			to_del = curr;
		}
		else
		{
			to_del = curr->next;
			curr->next = curr->next->next;
		}
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
		return (newbuf);
	newbuf->buf_size = -2;
	newbuf->fd = fd;
	newbuf->eof = false;
	if (ft_lstlocate(&lcl, *lst, fd))
	{
		free (newbuf);
		if (((t_buffer *)(lcl->content))->fd == fd)
			return (lcl->content);
		else
			return (lcl->next->content);
	}
	if (lcl)
		lcl->next = ft_lstnew(newbuf);
	else
		*lst = ft_lstnew(newbuf);
	return (newbuf);
}

int	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != 0)
	{
		cnt++;
	}
	return (cnt);
}
