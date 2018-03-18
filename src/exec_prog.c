/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:10:44 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/18 16:23:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void	exec_prog(t_cli *cli)
{
	extern pid_t	g_pid;

	if ((g_pid = fork()) < 0)
		ft_putendl_fd("Fork returned error!!!", 2);
	else if (!g_pid)
	{
		execve(PTH, ACMD, cli->env);
	}
	wait(NULL);
}
