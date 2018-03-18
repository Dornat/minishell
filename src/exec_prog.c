/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:10:44 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/18 19:06:18 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void	exec_prog(t_cli *cli)
{
	extern pid_t	g_pid;
	extern struct termios g_raw;

	if ((g_pid = fork()) < 0)
		ft_putendl_fd("Fork returned error!!!", 2);
	else if (!g_pid)
	{
		disable_raw_mode();
		execve(PTH, ACMD, cli->env);
	}
	wait(NULL);
	tcsetattr(0, TCSAFLUSH, &g_raw);
	//enable_raw_mode();
}
