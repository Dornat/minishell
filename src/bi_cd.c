/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:01:50 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 10:50:57 by dpolosuk         ###   ########.fr       */
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

void				bi_cd(t_cli *cli)
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
