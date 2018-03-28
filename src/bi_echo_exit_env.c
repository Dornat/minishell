/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo_exit_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:29:58 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 12:14:27 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

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
		if (ACMD[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		check_for_builtin(t_cli *cli)
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
