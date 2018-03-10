/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:15:38 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/10 15:29:37 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		crs_move_right(t_cli *cli)
{
	if (cli->crs.col == cli->crs.w_cols - 1)
	{
		tputs(tgetstr(MV_DOWN, NULL), 0, ft_putcchar);
		tputs(tgetstr(MV_BEG, NULL), 0, ft_putcchar);
		cli->crs.col = 0;
		cli->crs.row += 1;
	}
	else
	{
		tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
		cli->crs.col += 1;
	}
}

static void		crs_move_left(t_cli *cli)
{
	if (cli->crs.col == 0)
	{
		tputs(tgetstr(MV_UP, NULL), 0, ft_putcchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, cli->crs.w_cols - 1), 0, ft_putcchar);
		cli->crs.col = cli->crs.w_cols - 1;
		cli->crs.row -= 1;
	}
	else
	{
		tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
		cli->crs.col -= 1;
	}
}

static int		crs_chk_mv_right(char *c, t_cli *cli)
{
	int		ptr;

	ptr = 0;
	if (cli->crs.row > 0)
		ptr = cli->crs.row * cli->crs.w_cols + cli->crs.col;
	else
		ptr = cli->crs.col;
	if ((ptr < (int)ft_strlen(cli->cmd) + cli->crs.prmt_l) &&
		(!ft_strcmp(c, RIGHT_ARROW) || !ft_strcmp(c, CTRL_F)))
		return (1);
	return (0);
}

static int		crs_chk_mv_left(char *c, t_cli *cli)
{
	if ((cli->crs.row || (!cli->crs.row && cli->crs.col > cli->crs.prmt_l)) &&
		(!ft_strcmp(c, LEFT_ARROW) || !ft_strcmp(c, CTRL_B)))
		return (1);
	return (0);	
}

void			key_process(char *c, t_cli *cli)
{
	if (!ft_isnotprint(c[0]))
		insert_chr_in_cmdl(c, cli);
	else if (crs_chk_mv_left(c, cli))
		crs_move_left(cli);
	else if (crs_chk_mv_right(c, cli))
		crs_move_right(cli);
	else if (!ft_strcmp(c, ENTER_KEY))
	{
		printf("\ncli->crs.col: %d\n", cli->crs.col);
		printf("cli->crs.w_cols: %d\n", cli->crs.w_cols);
		printf("cli->cmd: %s\n", cli->cmd);
		printf("cli->crs.row: %d\n", cli->crs.row);
		printf("len of cli->cmd: %d\n", (int)ft_strlen(cli->cmd));
		printf("cli->crs.grows: %d\n", cli->crs.grows);
		printf("cli->prt.len: %d\n", cli->prt.len);
		printf("modulo: %d\n", (cli->prt.len + (int)ft_strlen(cli->cmd)) % cli->crs.w_cols);
	}
}
