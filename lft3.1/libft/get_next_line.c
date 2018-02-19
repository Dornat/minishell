/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:49:59 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/09 12:30:02 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static t_list	*ft_lstnew2(void const *content, size_t content_size)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		res->content = malloc(2);
		ft_memcpy(res->content, content, 2);
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}

static t_list	*find_fd(const int fd, t_list **all)
{
	t_list		*tmp;

	tmp = *all;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew2("\0", fd);
	ft_lstadd(all, tmp);
	tmp = *all;
	return (tmp);
}

static int		read_from_file(const int fd, t_list **ptr)
{
	int		ret;
	char	*to_free;
	char	*tmp;

	tmp = ft_memalloc(BUFF_SIZE + 1);
	if (!ft_strchr((*ptr)->content, '\n'))
	{
		while ((ret = read(fd, tmp, BUFF_SIZE)))
		{
			if (ret == -1)
			{
				ft_memdel((void**)&tmp);
				return (0);
			}
			tmp[ret] = '\0';
			to_free = (*ptr)->content;
			(*ptr)->content = ft_strjoin((*ptr)->content, tmp);
			ft_memdel((void**)&to_free);
			if ((ft_strchr(tmp, '\n')))
				break ;
		}
	}
	ft_memdel((void**)&tmp);
	return (1);
}

static int		write_to_line(t_list **ptr, char **line)
{
	if (!ft_strchr((*ptr)->content, '\n') && (*ptr)->content)
	{
		*line = ft_strdup((*ptr)->content);
		((char*)(*ptr)->content)[0] = '\0';
		return (1);
	}
	else
		*line = ft_strsub((*ptr)->content, 0,
				ft_strchr((*ptr)->content, '\n') - (char*)(*ptr)->content);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*all;
	t_list			*ptr;
	char			*to_free;
	char			its_alive[1];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, its_alive, 0) < 0)
		return (-1);
	ptr = find_fd(fd, &all);
	if (!read_from_file(fd, &ptr))
		return (-1);
	if (!((char*)ptr->content)[0])
		return (0);
	if (write_to_line(&ptr, line))
		return (1);
	to_free = ptr->content;
	if (ft_strchr(ptr->content, '\n'))
	{
		ptr->content = ft_strchr(ptr->content, '\n') + 1;
		ptr->content = ft_strdup(ptr->content);
	}
	else if (!(ptr->content))
		return (0);
	ft_memdel((void**)&to_free);
	return (1);
}
