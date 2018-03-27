/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pwd_oldpwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:02:56 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 15:42:50 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void			swap_pwd_oldpwd_if2(t_list *env, t_list **pold)
{
	t_list		*new;

	new = ft_lstnew("OLDPWD=", 7);
	ft_lstadd_atend(&env, new);
	*pold = bi_find_env(env, "OLDPWD=");
}

static void			set_pwd(t_list *env, t_list **ppwd, char *buf)
{
	t_list		*new;

	new = ft_lstnew("PWD=", PATH_LEN);
	ft_strcat(new->content, buf);
	ft_lstadd_atend(&env, new);
	*ppwd = bi_find_env(env, "PWD=");
}

void				swap_pwd_oldpwd(t_list *env)
{
	t_list		*ppwd;
	t_list		*pold;
	t_list		*new;
	char		*buf;

	new = NULL;
	buf = NULL;
	buf = getcwd(buf, PATH_LEN);
	if (!(ppwd = bi_find_env(env, "PWD=")))
		set_pwd(env, &ppwd, buf);
	if (!(pold = bi_find_env(env, "OLDPWD=")))
		swap_pwd_oldpwd_if2(env, &pold);
	ft_memdel(&pold->content);
	pold->content_size = PATH_LEN;
	pold->content = (void*)ft_strnew(pold->content_size);
	ft_memcpy(pold->content, "OLDPWD=", 7);
	ft_memcpy(pold->content + 7, (char*)ppwd->content + 4,
				ft_strlen((const char*)ppwd->content + 4));
	ft_memdel(&ppwd->content);
	ppwd->content_size = PATH_LEN;
	ppwd->content = (void*)ft_strnew(ppwd->content_size);
	ft_memcpy(ppwd->content, "PWD=", 4);
	ft_memcpy(ppwd->content + 4, (const void*)buf, ft_strlen(buf));
	ft_strdel(&buf);
}
