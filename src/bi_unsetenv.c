/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:40:36 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 12:20:40 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

t_list		*bi_find_unsetenv(t_cli *cli)
{
	t_list		*ptr;
	int			i;

	ptr = ENV;
	i = 0;
	if (!ptr || !ACMD[1])
		return (NULL);
	while (ptr)
	{
		if (!ft_strncmp(ACMD[1], (char*)ptr->content, ft_strlen(ACMD[1])))
		{
			while (((char*)ptr->content)[i] != '=')
				i++;
			if ((int)ft_strlen(ACMD[1]) == i)
				return (ptr);
		}
		ptr = ptr->next;
	}
	return (NULL);
}

void		bi_unsetenv(t_cli *cli)
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
		while (before && before->next != ptr)
			before = before->next;
		if ((after = ptr->next) == NULL)
		{
			ft_lstdelone(&ptr, ft_lstdelfunc);
			before->next = NULL;
		}
		else
		{
			ft_lstdelone(&ptr, ft_lstdelfunc);
			before->next = after;
		}
	}
}
