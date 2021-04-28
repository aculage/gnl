#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	cur = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	return ;
}

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

t_list	*ft_fndbyfd(t_list *lst, int fd)
{
	if (lst)
	{
		while (((t_buffer *)lst->content)->fd != fd)
		{
			lst = lst->next;
			if (!lst)
				return (NULL);
		}
	}
	return (lst);
}

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	int	shft;

	shft = 0;
	if (src > dest)
	{
		while (shft < (int) count)
		{
			*((unsigned char *)dest + shft) = *((unsigned char *)src + shft);
			shft++;
		}
	}
	if (src < dest)
	{
		shft = count - 1 ;
		while (shft >= 0)
		{
			*((unsigned char *)dest + shft) = *((unsigned char *)src + shft);
			shft--;
		}
	}
	return (dest);
}
