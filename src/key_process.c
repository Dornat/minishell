/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:15:38 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/10 17:28:28 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		crs_move_right(t_cli *cli)
{
	if (CRS.col == CRS.w_cols - 1)
	{
		tputs(tgetstr(MV_DOWN, NULL), 0, ft_putcchar);
		tputs(tgetstr(MV_BEG, NULL), 0, ft_putcchar);
		CRS.col = 0;
		CRS.row += 1;
	}
	else
	{
		tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
		CRS.col += 1;
	}
}

static void		crs_move_left(t_cli *cli)
{
	if (CRS.col == 0)
	{
		tputs(tgetstr(MV_UP, NULL), 0, ft_putcchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, CRS.w_cols - 1), 0, ft_putcchar);
		CRS.col = CRS.w_cols - 1;
		CRS.row -= 1;
	}
	else
	{
		tputs(tgetstr(MV_LEFT, NULL), 0, ft_putcchar);
		CRS.col -= 1;
	}
}

static int		crs_chk_mv_right(char *c, t_cli *cli)
{
	int		ptr;

	ptr = 0;
	if (CRS.row > 0)
		ptr = CRS.row * CRS.w_cols + CRS.col;
	else
		ptr = CRS.col;
	if ((ptr < (int)ft_strlen(cli->cmd) + CRS.prmt_l) &&
		(!ft_strcmp(c, RIGHT_ARROW) || !ft_strcmp(c, CTRL_F)))
		return (1);
	return (0);
}

static int		crs_chk_mv_left(char *c, t_cli *cli)
{
	if ((CRS.row || (!CRS.row && CRS.col > CRS.prmt_l)) &&
		(!ft_strcmp(c, LEFT_ARROW) || !ft_strcmp(c, CTRL_B)))
		return (1);
	return (0);	
}

static int		crs_chk_del(char *c, t_cli *cli)
{
	if ((CRS.row || (!CRS.row && CRS.col > CRS.prmt_l)) &&
		(!ft_strcmp(c, DEL_KEY)))
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
	else if (crs_chk_del(c, cli))
		del_chr_from_cmdl(cli);
	else if (!ft_strcmp(c, ENTER_KEY))
	{
		printf("\nCRS.col: %d\n", CRS.col);
		printf("CRS.w_cols: %d\n", CRS.w_cols);
		printf("cli->cmd: %s\n", cli->cmd);
		printf("CRS.row: %d\n", CRS.row);
		printf("len of cli->cmd: %d\n", (int)ft_strlen(cli->cmd));
		printf("CRS.grows: %d\n", CRS.grows);
		printf("cli->prt.len: %d\n", cli->prt.len);
		printf("modulo: %d\n", (cli->prt.len + (int)ft_strlen(cli->cmd)) % CRS.w_cols);
	}
}
