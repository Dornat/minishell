/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:13:45 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/18 18:43:36 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

pid_t			g_pid;
struct termios	g_orig_termios;
struct termios	g_raw;

void	free_acmd(char **s)
{
	int		i;
	
	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	free(s);
}

void	test(int kp, char *c, t_cli *cli)
{
	while (1)
	{
		ft_putstr(PRT.p);
		while (1)
		{
			ft_bzero(c, 5);
			read(0, c, 5);
			if ((kp = key_process(c, cli)) == -1)
			{
				ft_bzero(CMD, ft_strlen(CMD));
				ft_putchar('\n');
				break ;
			}
			else if (kp == 1)
			{
				ft_putchar('\n');
				if (parse_cmd(cli))
				{
					if (ACMD[0])
						ft_printf("msh: %s: command not found\n", ACMD[0]);
				}
				else if (TMP[0])
				{
					exec_prog(cli);
				}
				ft_bzero(CMD, ft_strlen(CMD));
				ft_bzero(TMP, ft_strlen(TMP));
				free_acmd(ACMD);
				break ;
			}
		}
	}
}

void	signal_handler(int sig)
{
	if (!g_pid)
	{
		ft_putchar('\n');
		exit(sig);
	}
	else
		;
}

int		main(void)
{
	char		c[5];
	t_cli		cli;
	int			kp;

	init_term_data(&cli);
	kp = 0;
	g_pid = 1;
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, SIG_IGN);
	test(kp, c, &cli);
	/* while (1) */
	/* { */
	/* 	ft_putstr(cli.prt.p); */
	/* 	while (1) */
	/* 	{ */
	/* 		ft_bzero(c, 5); */
	/* 		read(0, c, 5); */
	/* 		if ((kp = key_process(c, &cli)) == -1) */
	/* 		{ */
	/* 			ft_bzero(cli.cmd, ft_strlen(cli.cmd)); */
	/* 			ft_putchar('\n'); */
	/* 			break ; */
	/* 		} */
	/* 		else if (kp == 1) */
	/* 		{ */
	/* 			parse_cmd(&cli); */
	/* 			ft_putchar('\n'); */
	/* 			if (cli.tcmd[0]) */
	/* 			{ */
	/* 				exec_prog(&cli); */
	/* 				//ft_putchar('\n'); */
	/* 			} */
	/* 			ft_bzero(cli.cmd, ft_strlen(cli.cmd)); */
	/* 			ft_bzero(cli.tcmd, ft_strlen(cli.tcmd)); */
	/* 			break ; */
	/* 		} */
	/* 	} */
	/* } */
}
