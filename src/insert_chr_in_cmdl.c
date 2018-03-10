/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chr_in_cmdl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:19:38 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/10 16:00:08 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void	crs_go_back_from_beg(t_cli *cli)
{
	int		row;
	int		col;

	row = cli->crs.row;
	col = cli->crs.col;
	while (row)
	{
		tputs(tgetstr(MV_DOWN, NULL), 0, ft_putcchar);
		row--;
	}
	while (col--)
		tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
}

void	reset_crs_2(t_cli *cli)
{
	int		row;

	row = cli->crs.grows;
	if (row)
	{
		while (row--)
			tputs(tgetstr(MV_UP, NULL), 0, ft_putcchar);
	}
	tputs(tgetstr(MV_BEG, NULL), 0, ft_putcchar);
}

void	reset_crs(t_cli *cli)
{
	int		row;

	row = cli->crs.row;
	if (row)
	{
		while (row--)
			tputs(tgetstr(MV_UP, NULL), 0, ft_putcchar);
	}
	tputs(tgetstr(MV_BEG, NULL), 0, ft_putcchar);
}

void	refresh_cli(t_cli *cli, int mid_flag)
{
	reset_crs(cli);
	tputs(tgetstr(CLEAR_SCREEN, NULL), 0, ft_putcchar);
	tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
	ft_putstr_fd(cli->prt.p, 0);
	ft_putstr_fd(cli->cmd, 0);
	tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
	reset_crs_2(cli);
	crs_go_back_from_beg(cli);
}

static void		ins_in_middle_of_cmdl(char *c, t_cli *cli)
{
	char	*dst;
	char	*src;
	int		ptr;

	if (cli->crs.row)
		ptr = cli->crs.w_cols * cli->crs.row + cli->crs.col - cli->prt.len;
	else
		ptr = cli->crs.col - cli->prt.len;
	dst = cli->cmd + ptr + ft_strlen(c);
	src = cli->cmd + ptr;
	ft_memmove(dst, src, ft_strlen(src));
	ft_memmove(src, c, ft_strlen(c));
}

static int		chk_if_crs_in_mid(t_cli *cli, int *mid_flag)
{
	int		ptr;

	if (cli->crs.row)
		ptr = (cli->crs.row * cli->crs.w_cols) + cli->crs.col;
	else
		ptr = cli->crs.col;
	if (ptr < (int)ft_strlen(cli->cmd) + cli->prt.len)
	{
		*mid_flag = 1;
		return (1);
	}
	return (0);
}

void			insert_chr_in_cmdl(char *c, t_cli *cli)
{
	int		mid_flag;

	mid_flag = 0;
	tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
	ft_putstr_fd(c, 0);
	if (chk_if_crs_in_mid(cli, &mid_flag))
		ins_in_middle_of_cmdl(c, cli);
	else
		ft_strcat(cli->cmd, c);
	if (cli->crs.col < cli->crs.w_cols - 1)
		cli->crs.col += 1;
	else
	{
		tputs(tgetstr(MV_DOWN, NULL), 0, ft_putcchar);
		cli->crs.col = 0;
		cli->crs.row += 1;
	}
	if ((cli->prt.len + (int)ft_strlen(cli->cmd)) == cli->crs.w_cols)
		cli->crs.grows = 0;
	else
	{
		if ((cli->prt.len + (int)ft_strlen(cli->cmd)) % cli->crs.w_cols)
			cli->crs.grows = (cli->prt.len + (int)ft_strlen(cli->cmd)) / cli->crs.w_cols;
		else
			cli->crs.grows = (cli->prt.len + (int)ft_strlen(cli->cmd)) / (cli->crs.w_cols + 1);
	}
	tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
	refresh_cli(cli, mid_flag);
}
