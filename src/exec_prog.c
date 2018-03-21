/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:10:44 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/21 12:42:41 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void	exec_prog(t_cli *cli)
{
	extern pid_t			g_pid;
	extern struct termios	g_raw;
	extern char				**environ;

	if ((g_pid = fork()) < 0)
		ft_putendl_fd("Fork returned error!!!", 2);
	else if (!g_pid)
	{
		disable_raw_mode();
		execve(PTH, ACMD, environ);
	}
	wait(NULL);
	g_pid = 0;
	tcsetattr(0, TCSAFLUSH, &g_raw);
}
