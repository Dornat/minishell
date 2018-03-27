/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:54:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 14:06:23 by dpolosuk         ###   ########.fr       */
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

static int		find_executable_with_path(char *pth)
{
	if (access(pth, F_OK) == 0)
	{
		if (access(pth, X_OK) == -1)
			return (-1);
		else
			return (0);
	}
	else
		return (-2);
	return (-2);
}

int		append_pth_of_exec(t_cli *cli)
{
	if (!ACMD[0])
		return (0);
	ft_strcat(PTH, "/");
	ft_strcat(PTH, ACMD[0]);
	return (find_executable_with_path(PTH));
}

static int		find_executable(t_cli *cli)
{
	char	**dr;
	int		i;
	int		ret;

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
		if ((ret = append_pth_of_exec(cli)) == 0)
		{
			free_double_ptr(&dr);
			return (ret);
		}
		i++;
	}
	free_double_ptr(&dr);
	return (ret);
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
	free_double_ptr(&BIS);
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

void	bi_echo(t_cli *cli)
{
	int		i;

	i = 1;
	while (ACMD[i])
	{
		ft_putstr(ACMD[i]);
		i++;
	}
	ft_putchar('\n');
}

void	(*bi_ptr[6]) (t_cli *cli) =
{
	bi_exit, bi_cd, bi_env, bi_setenv, bi_unsetenv, bi_echo
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
	else if (!ft_strcmp(ACMD[0], "echo"))
		BI = ech;
	else
		return (0);
	return (1);
}

static int		parse_cmd_if(t_cli *cli)
{
	if (!ft_strcmp(ACMD[0], "/usr/bin/env"))
	{
		BIF = 1;
		BI = env;
		return (0);
	}
	if (PTH[0] == '\0')
		ft_memcpy(PTH, ACMD[0], ft_strlen(ACMD[0]));
	else
	{
		ft_bzero(PTH, ft_strlen(PTH));
		ft_memcpy(PTH, ACMD[0], ft_strlen(ACMD[0]));
	}
	return (find_executable_with_path(ACMD[0]));
}

int				parse_cmd(t_cli *cli)
{
	int		ret;
	
	ret = 0;
	if (!(ACMD = msh_split(CMDS[I], cli)))
		return (1);
	if (check_for_builtin(cli))
	{
		BIF = 1;
		return (0);
	}
	if (ft_strrchr(ACMD[0], '/'))
		return (parse_cmd_if(cli));
	else if (path_exist(cli))
	{
		if ((ret = find_executable(cli)) == 0)
			return (0);
	}
	if (ret == -1)
		return (ret);
	return (1);
}
