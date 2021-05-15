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

t_buffer	*ft_getbyfd(t_list **lst, int fd)
{
	t_buffer	*newbuf;
	t_list		*lcl;

	newbuf = malloc(sizeof(t_buffer));
	newbuf->buf_size = -2;
	newbuf->fd = fd;
	newbuf->eof = false;
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
