/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:55:03 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 15:58:28 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void			disable_raw_mode(void)
{
	extern struct termios	g_orig_termios;

	tcsetattr(0, TCSANOW, &g_orig_termios);
}

static void		enable_raw_mode(void)
{
	extern struct termios		g_raw;
	extern struct termios		g_orig_termios;

	tcgetattr(0, &g_raw);
	g_orig_termios = g_raw;
	g_raw.c_lflag &= ~(ICANON);
	g_raw.c_lflag &= ~(ECHO);
	g_raw.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &g_raw);
}

static void		init_cpos(t_cli *cli)
{
	struct winsize		ws;

	ioctl(0, TIOCGWINSZ, &ws);
	cli->crs.w_cols = ws.ws_col;
	cli->crs.w_rows = ws.ws_row;
	cli->crs.col = cli->prt.len;
	cli->crs.row = 0;
}

static void		init_term_data2(t_cli *cli)
{
	cli->bs = 0;
	cli->cmds = NULL;
	cli->cmds_i = 0;
	cli->acmd = NULL;
	cli->brk = 0;
	cli->dqt = 0;
	cli->epth = NULL;
}

void			init_term_data(t_cli *cli)
{
	extern char		g_prompt[PATH_LEN];
	char			buf[CONV_MAX_BUFF];
	char			*termtype;

	termtype = find_term_type();
	tgetent(buf, termtype);
	ft_strdel(&termtype);
	enable_raw_mode();
	cli->env = copy_env();
	shlvl_increase(cli);
	PRT.p = ft_strnew(PATH_LEN);
	init_prompt(cli);
	ft_bzero(g_prompt, PATH_LEN);
	ft_memcpy(g_prompt, PRT.p, ft_strlen(PRT.p));
	cli->prt.tp = NULL;
	cli->prt.len = ft_strlen(cli->prt.p) - 9;
	cli->cmd = ft_strnew(CMD_LEN);
	cli->tcmd = ft_strnew(CMD_LEN);
	init_term_data2(cli);
	cli->pth = ft_strnew(PATH_LEN);
	cli->bi_flag = 0;
	cli->bis = fill_bi_names();
	init_cpos(cli);
}
