/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_chr_from_cmdl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:48:15 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/10 17:31:30 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		del_from_middle_of_cmdl(t_cli *cli)
{
	char	*dst;
	char	*src;
	int		ptr;

	if (CRS.row)
		ptr = CRS.w_cols * CRS.row + CRS.col - PRT.len;
	else
		ptr = CRS.col - PRT.len;
	dst = CMD + ptr - 1;
	src = CMD + ptr;
	ft_memmove(dst, src, ft_strlen(src));
	CMD[ft_strlen(CMD) - 1] = '\0';
}

static int		del_chk_if_crs_in_mid(t_cli *cli, int *mid_flag)
{
	int		ptr;

	if (CRS.row)
		ptr = (CRS.row * CRS.w_cols) + CRS.col;
	else
		ptr = CRS.col;
	if (ptr < (int)ft_strlen(CMD) + PRT.len)
	{
		*mid_flag = 1;
		return (1);
	}
	return (0);
}

static void		del_global_rows_update(t_cli *cli)
{
	if ((PRT.len + (int)ft_strlen(CMD)) == CRS.w_cols)
		CRS.grows = 0;
	else
	{
		if ((PRT.len + (int)ft_strlen(CMD)) % CRS.w_cols)
			CRS.grows = (PRT.len + (int)ft_strlen(CMD)) / CRS.w_cols;
		else
			CRS.grows = (PRT.len + (int)ft_strlen(CMD)) / (CRS.w_cols + 1);
	}
}

void	del_chr_from_cmdl(t_cli *cli)
{
	int		mid_flag;

	mid_flag = 0;
	if (del_chk_if_crs_in_mid(cli, &mid_flag))
		del_from_middle_of_cmdl(cli);
	else
		CMD[ft_strlen(CMD) - 1] = '\0';
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
	del_global_rows_update(cli);
	refresh_cli(cli);
}
