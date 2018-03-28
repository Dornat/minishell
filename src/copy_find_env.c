/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_find_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:09:32 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 12:09:58 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

t_list		*copy_env(void)
{
	extern char		**environ;
	t_list			*res;
	t_list			*tmp;
	int				i;

	if (!environ)
		return (NULL);
	i = 1;
	res = ft_lstnew(environ[0], ft_strlen(environ[0]));
	while (environ[i])
	{
		tmp = ft_lstnew(environ[i], ft_strlen(environ[i]));
		ft_lstadd_atend(&res, tmp);
		i++;
	}
	return (res);
}

t_list		*bi_find_env(t_list *env, char *arg)
{
	t_list		*ptr;

	ptr = env;
	if (!ptr || !arg)
		return (NULL);
	while (ptr)
	{
		if (!ft_strncmp(arg, (char*)ptr->content, ft_strlen(arg)))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
