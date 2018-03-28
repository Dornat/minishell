/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_find_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:09:32 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 15:56:46 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

t_list			*copy_env(void)
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

t_list			*bi_find_env(t_list *env, char *arg)
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

static void		set_shlvl(t_list *env)
{
	t_list		*new;

	new = ft_lstnew("SHLVL=1", 7);
	ft_lstadd_atend(&env, new);
}

void			shlvl_increase(t_cli *cli)
{
	char		*ev;
	int			evn;
	char		*evni;
	t_list		*p;

	if ((ev = grep_envvalue("SHLVL", cli)) == NULL)
		set_shlvl(ENV);
	else
	{
		evn = ft_atoi(ev);
		evn = evn + 1;
		evni = ft_itoa(evn);
		p = bi_find_env(ENV, "SHLVL=");
		ft_memdel(&p->content);
		p->content_size = 42;
		p->content = (void*)ft_strnew(p->content_size);
		ft_strcat(p->content, "SHLVL=");
		ft_strcat(p->content, evni);
		ft_strdel(&evni);
		ft_strdel(&ev);
	}
}
