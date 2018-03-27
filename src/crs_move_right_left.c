/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crs_move_right_left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:12:39 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 15:14:27 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

void		crs_move_right(t_cli *cli)
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

void		crs_move_left(t_cli *cli)
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
