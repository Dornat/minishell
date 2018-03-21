/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:54:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/21 17:14:55 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

int		path_exist(t_cli *cli)
{
	t_list		*ptr;

	ptr = ENV;
	while (ptr)
	{
		if (((char*)ptr->content)[0] == 'P')
		{
			if (!ft_strncmp((char*)ptr->content, "PATH=", 5))
			{
				if (!EPTH)
					EPTH = ft_strdup((char*)ptr->content);
				return (1);
			}
		}
		ptr = ptr->next;
	}
	if (EPTH)
		ft_strdel(&EPTH);
	return (0);
}

int		append_pth_of_exec(t_cli *cli)
{
	DIR					*dir_ptr;
	struct dirent		*dir_struct;

	if (!ACMD[0])
		return (0);
	dir_ptr = opendir(PTH);
	while ((dir_struct = readdir(dir_ptr)) != NULL)
	{
		if (!ft_strcmp(ACMD[0], dir_struct->d_name))
		{
			ft_strcat(PTH, "/");
			ft_strcat(PTH, ACMD[0]);
			closedir(dir_ptr);
			return (1);
		}
	}
	closedir(dir_ptr);
	return (0);
}

int		find_executable(t_cli *cli)
{
	char	**dr;
	int		i;

	if (!(dr = ft_strsplit(EPTH + 5, ':')))
		return (0);
	i = 0;
	while (dr[i])
	{
		if (PTH[0] == '\0')
			ft_memcpy(PTH, dr[i], ft_strlen(dr[i]));
		else
		{
			ft_bzero(PTH, ft_strlen(PTH));
			ft_memcpy(PTH, dr[i], ft_strlen(dr[i]));
		}
		if (append_pth_of_exec(cli))
		{
			free_double_ptr(&dr);
			return (1);
		}
		i++;
	}
	free_double_ptr(&dr);
	return (0);
}

void	bi_exit(t_cli *cli)
{
	ft_strdel(&PRT.p);
	ft_strdel(&CMD);
	ft_strdel(&TMP);
	ft_lstdel(&ENV, ft_lstdelfunc);
	ft_strdel(&PTH);
	if (EPTH)
		ft_strdel(&EPTH);
	free_double_ptr(&ACMD);
	disable_raw_mode();
	exit(0);
}

void	bi_env(t_cli *cli)
{
	extern struct termios	g_raw;
	t_list					*ptr;

	ptr = ENV;
	disable_raw_mode();
	while (ptr)
	{
		ft_putstr((char*)ptr->content);
		ft_putchar('\n');
		ptr = ptr->next;
	}
	tcsetattr(0, TCSAFLUSH, &g_raw);
}

void	(*bi_ptr[5]) (t_cli *cli) =
{
	bi_exit, bi_cd, bi_env, bi_setenv, bi_unsetenv
};

void		exec_builtin(t_cli *cli)
{
	(*bi_ptr[BI]) (cli);
}

static int		check_for_builtin(t_cli *cli)
{
	if (!ft_strcmp(ACMD[0], "exit"))
		BI = ext;
	else if (!ft_strcmp(ACMD[0], "cd"))
		BI = cd;
	else if (!ft_strcmp(ACMD[0], "env"))
		BI = env;
	else if (!ft_strcmp(ACMD[0], "setenv"))
		BI = setnv;
	else if (!ft_strcmp(ACMD[0], "unsetenv"))
		BI = unsetnv;
	else
		return (0);
	return (1);
}

int		parse_cmd(t_cli *cli)
{
	if (!(ACMD = ft_strsplit(TMP, ' ')))
		return (1);
	if (check_for_builtin(cli))
	{
		BIF = 1;
		return (0);
	}
	if (ft_strrchr(ACMD[0], '/'))
	{
		if (PTH[0] == '\0')
			ft_memcpy(PTH, ACMD[0], ft_strlen(ACMD[0]));
		else
		{
			ft_bzero(PTH, ft_strlen(PTH));
			ft_memcpy(PTH, ACMD[0], ft_strlen(ACMD[0]));
		}
		return (0);
	}
	else if (path_exist(cli))
	{
		if (find_executable(cli))
			return (0);
	}
	return (1);
}
