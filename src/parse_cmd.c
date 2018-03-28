/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:54:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 11:45:11 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void			(*g_bi_ptr[6]) (t_cli *cli) =
{
	bi_exit, bi_cd, bi_env, bi_setenv, bi_unsetenv, bi_echo
};

void			exec_builtin(t_cli *cli)
{
	(*g_bi_ptr[BI])(cli);
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
