/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:12:04 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 16:41:36 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		(*f)(tmp);
		tmp = tmp->next;
	}
}

int		ft_lstlen(t_list *lst)
{
	t_list		*p;
	int			i;

	p = lst;
	i = 0;
	if (lst == NULL)
		return (0);
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}
