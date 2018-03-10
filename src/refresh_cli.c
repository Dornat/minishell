/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_cli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:35:54 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/10 16:38:19 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		crs_go_back_from_beg(t_cli *cli)
{
	int		row;
	int		col;

	row = CRS.row;
	col = CRS.col;
	while (row)
	{
		tputs(tgetstr(MV_DOWN, NULL), 0, ft_putcchar);
		row--;
	}
	while (col--)
		tputs(tgetstr(MV_RIGHT, NULL), 0, ft_putcchar);
}

static void		reset_crs_2(t_cli *cli)
{
	int		row;

	row = CRS.grows;
	if (row)
	{
		while (row--)
			tputs(tgetstr(MV_UP, NULL), 0, ft_putcchar);
	}
	tputs(tgetstr(MV_BEG, NULL), 0, ft_putcchar);
}

static void		reset_crs(t_cli *cli)
{
	int		row;

	row = CRS.row;
	if (row)
	{
		while (row--)
			tputs(tgetstr(MV_UP, NULL), 0, ft_putcchar);
	}
	tputs(tgetstr(MV_BEG, NULL), 0, ft_putcchar);
}

void			refresh_cli(t_cli *cli)
{
	reset_crs(cli);
	tputs(tgetstr(CLEAR_SCREEN, NULL), 0, ft_putcchar);
	tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
	ft_putstr_fd(PRT.p, 0);
	ft_putstr_fd(CMD, 0);
	tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
	reset_crs_2(cli);
	crs_go_back_from_beg(cli);
}
