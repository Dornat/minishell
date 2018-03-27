/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:13:45 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 12:49:40 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

/*
** g_pid - for saving pid of a process
** g_orig_termios - for saving original term state
** g_raw - raw term state
** g_ptompt - for saving prompt (for ^C handling)
** g_ctrl - for checking ^C press when handling quoting
*/

pid_t			g_pid;
struct termios	g_orig_termios;
struct termios	g_raw;
char			g_prompt[PATH_LEN];
int				g_ctrl;

void	free_double_ptr(char ***s)
{
	int		i;
	
	i = 0;
	if (!s || !*s)
		return ;
	while ((*s)[i])
	{
		ft_strdel(&(*s)[i]);
		i++;
	}
	free(*s);
	*s = NULL;
}

void	loops_if_g_ctrl(t_cli *cli)
{
	ft_bzero(TMP, ft_strlen(TMP));
	ft_bzero(CMD, ft_strlen(CMD));
	CRS.col = PRT.len;
	g_ctrl = 0;
}

void	loops_elif_while(t_cli *cli, int no_such_file)
{
	if ((no_such_file = parse_cmd(cli)))
	{
		if (no_such_file == -1)
			ft_printf("msh: %s: Permission denied\n", ACMD[0]);
		else if (no_such_file == -2)
			ft_printf("msh: %s: No such file or directory\n", ACMD[0]);
		else if (ACMD[0])
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
}

void	loops_elif(t_cli *cli, int no_such_file)
{
	ft_putchar('\n');
	CMDS = split_semicol(TMP);
	I = 0;
	while (CMDS[I])
	{
		loops_elif_while(cli, no_such_file);
		free_double_ptr(&ACMD);
		I = I + 1;
	}
	init_prompt(cli);
	ft_bzero(g_prompt, ft_strlen(g_prompt));
	ft_strcpy(g_prompt, PRT.p);
	PRT.len = ft_strlen(PRT.p) - 9;
	CRS.col = PRT.len;
	ft_bzero(CMD, ft_strlen(CMD));
	ft_bzero(TMP, ft_strlen(TMP));
	free_double_ptr(&CMDS);
}

void	loops(int kp, char *c, t_cli *cli)
{
	int		no_such_file;
	
	while (1)
	{
		ft_putstr(PRT.p);
		while (1)
		{
			ft_bzero(c, 5);
			read(0, c, 5);
			no_such_file = -1;
			if (g_ctrl)
				loops_if_g_ctrl(cli);
			if ((kp = key_process(c, cli)) == -1)
			{
				ft_bzero(CMD, ft_strlen(CMD));
				ft_putchar('\n');
				break ;
			}
			else if (kp == 1)
			{
				loops_elif(cli, no_such_file);
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
	g_ctrl = 1;
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
	loops(kp, c, &cli);
}
