/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:13:45 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/21 12:46:49 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

pid_t			g_pid;
struct termios	g_orig_termios;
struct termios	g_raw;
char			g_prompt[256];

void	free_double_ptr(char **s)
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

void	loops(int kp, char *c, t_cli *cli)
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
					if (BIF)
					{
						exec_builtin(cli);
						BIF = 0;
					}
					else
						exec_prog(cli);
				}
				ft_bzero(CMD, ft_strlen(CMD));
				ft_bzero(TMP, ft_strlen(TMP));
				free_double_ptr(ACMD);
				break ;
			}
		}
	}
}

void	signal_handler(int sig)
{
	signal(sig, SIG_IGN);
	if (g_pid == 0)
	{
		ft_putchar('\n');
		ft_putstr(g_prompt);
	}
	else
	{
		ft_putchar('\n');
		g_pid = 0;
	}
	signal(SIGINT, signal_handler);
}

int		main(void)
{
	char		c[5];
	t_cli		cli;
	int			kp;

	init_term_data(&cli);
	kp = 0;
	g_pid = 0;
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, SIG_IGN);
	loops(kp, c, &cli);
}
