/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:16:03 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/21 13:52:08 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

int			bi_env_exist(t_cli *cli)
{
	t_list		*ptr;

	ptr = ENV;
	while (ptr)
	{
		if (!ft_strncmp(ACMD[0], (char*)ptr->content, ft_strlen(ACMD[0])))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

char		*extract_env_name(char *env_field)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (env_field[i] != '=')
	{
		if (env_field[i] == '\0')
			return (res);
		i++;
	}
	res = ft_strnew(i);
	ft_memcpy(res, env_field, i);
	return (res);
}

t_list		*bi_find_env(t_cli *cli)
{
	t_list		*ptr;
	char		*cmp;

	ptr = ENV;
	cmp = extract_env_name(ACMD[1]);
	if (!ptr || !cmp)
		return (NULL);
	while (ptr)
	{
		if (!ft_strncmp(cmp, (char*)ptr->content, ft_strlen(cmp)))
		{
			ft_strdel(&cmp);
			return (ptr);
		}
		ptr = ptr->next;
	}
	ft_strdel(&cmp);
	return (NULL);
}

int			bi_is_eq_in_arg(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void		bi_setenv(t_cli *cli)
{
	t_list		*ptr;

	ptr = NULL;
	if ((ptr = bi_find_env(cli)))
	{
		ft_memdel(&ptr->content);
		ptr->content_size = ft_strlen(ACMD[1]);
		ptr->content = (void*)ft_strnew(ptr->content_size);
		ft_memcpy(ptr->content, (const void*)ACMD[1], ptr->content_size);
	}
	else
	{
		if (bi_is_eq_in_arg(ACMD[1]))
		{
			ptr = ft_lstnew((const void*)ACMD[1], ft_strlen(ACMD[1]));
			ft_lstadd_atend(&ENV, ptr);
		}
	}
}