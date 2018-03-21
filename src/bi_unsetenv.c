/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:40:36 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/21 14:09:25 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

t_list		*bi_find_unsetenv(t_cli *cli)
{
	t_list		*ptr;
	int			i;

	ptr = ENV;
	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr)
	{
		if (!ft_strncmp(ACMD[1], (char*)ptr->content, ft_strlen(ACMD[1])))
		{
			while (((char*)ptr->content)[i] != '=')
				i++;
			--i;
			if ((int)ft_strlen(ACMD[1]) == i)
				return (ptr);
		}
		ptr = ptr->next;
	}
	return (NULL);
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



void	bi_unsetenv(t_cli *cli)
{
	t_list		*ptr;
	t_list		*before;
	t_list		*after;

	before = ENV;
	ptr = NULL;
	after = NULL;
	if ((ptr = bi_find_unsetenv(cli)))
	{
		if (before == ptr)
			ft_lstdel_first_node(&ptr);
		while (before)
		{
			if (before->next == ptr)
				break ;
			before = before->next;
		}
		if ((after = ptr->next) == NULL)
			return ;
	}
}
