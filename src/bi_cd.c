/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:01:50 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 11:19:08 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

t_list				*find_home(t_cli *cli)
{
	t_list		*ptr;

	if (!(ptr = bi_find_env(ENV, "HOME=")))
		return (NULL);
	return (ptr);
}

static void			set_pwd(t_list *env, t_list **ppwd, char *buf)
{
	t_list		*new;

	new = ft_lstnew("PWD=", PATH_LEN);
	ft_strcat(new->content, buf);
	ft_lstadd_atend(&env, new);
	*ppwd = bi_find_env(env, "PWD=");
}

static void			swap_pwd_oldpwd(t_list *env)
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
	{
		new = ft_lstnew("OLDPWD=", 7);
		ft_lstadd_atend(&env, new);
		pold = bi_find_env(env, "OLDPWD=");
	}
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

static void			bi_change_dir(char *path, t_cli *cli)
{
	if (access(path, F_OK) == -1)
		ft_printf("msh: cd: %s: No such file or directory\n", path);
	else if (access(path, X_OK) == -1)
		ft_printf("msh: cd: %s: Permission denied\n", path);
	else
	{
		chdir(path);
		swap_pwd_oldpwd(ENV);
	}
}

static void			go_back(t_cli *cli)
{
	t_list		*ptr;

	if (!(ptr = bi_find_env(ENV, "OLDPWD=")))
		ft_putstr("msh: cd: OLDPWD not set\n");
	else
	{
		ft_putstr((char*)ptr->content + 7);
		ft_putchar('\n');
		bi_change_dir((char*)ptr->content + 7, cli);
	}
}

void	bi_cd(t_cli *cli)
{
	t_list		*ptr;

	ptr = NULL;
	if (!ACMD[1] || !ft_strcmp(ACMD[1], "--"))
	{
		if (!(ptr = find_home(cli)))
			ft_putstr("msh: cd: HOME not set\n");
		else
			bi_change_dir(((char*)ptr->content) + 5, cli);
	}
	else if (!ft_strcmp(ACMD[1], "-"))
		go_back(cli);
	else
		bi_change_dir(ACMD[1], cli);
}
