/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:26:22 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 12:02:41 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*tmp_n;

	tmp = *alst;
	while (tmp)
	{
		tmp_n = tmp->next;
		(*del)((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = tmp_n;
	}
	*alst = NULL;
}

void	ft_lstdel_first_node(t_list **alst)
{
	t_list		*ptr;

	ptr = *alst;
	if (!(*alst)->next)
		ft_lstdelone(alst, ft_lstdelfunc);
	else
	{
		*alst = (*alst)->next;
		ft_lstdelone(&ptr, ft_lstdelfunc);
	}
}

void	ft_lstdel_last_node(t_list **alst)
{
	t_list		*ptr;

	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ft_lstdelone(&ptr, ft_lstdelfunc);
}
