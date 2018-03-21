/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chr_in_cmdl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:19:38 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/21 14:59:54 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		ins_in_middle_of_cmdl(char *c, t_cli *cli)
{
	char	*dst;
	char	*src;
	int		ptr;

	if (CRS.row)
		ptr = CRS.w_cols * CRS.row + CRS.col - PRT.len;
	else
		ptr = CRS.col - PRT.len;
	dst = CMD + ptr + ft_strlen(c);
	src = CMD + ptr;
	ft_memmove(dst, src, ft_strlen(src));
	ft_memmove(src, c, ft_strlen(c));
}

static int		chk_if_crs_in_mid(t_cli *cli, int *mid_flag)
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

static void		global_rows_update(t_cli *cli)
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

static void		check_for_realloc(t_cli *cli)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = CMD;
	tmp2 = TMP;
	if ((ft_strlen(CMD) % 256 > 242) || (ft_strlen(TMP) % 256 > 242))
	{
		CMD = ft_strnew(ft_strlen(tmp1) * 2);
		ft_memcpy(CMD, tmp1, ft_strlen(tmp1));
		TMP = ft_strnew(ft_strlen(tmp2) * 2);
		ft_memcpy(TMP, tmp2, ft_strlen(tmp2));
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
}

void			check_for_ctrl_c(t_cli *cli)
{
	extern int		g_ctrl;

	if (!g_ctrl)
		return ;
	if (!ft_strcmp(PRT.p, "> "))
	{
		if (PRT.tp && PRT.p)
		{
			ft_strdel(&PRT.p);
			PRT.p = PRT.tp;
			PRT.tp = NULL;
			PRT.len = ft_strlen(PRT.p);
		}
		CRS.col = PRT.len;
		CRS.row = 0;
		BS = 0;
		ft_bzero(CMD, ft_strlen(CMD));
		ft_bzero(TMP, ft_strlen(TMP));
		g_ctrl = 0;
	}
	else
		g_ctrl = 0;
}

void			insert_chr_in_cmdl(char *c, t_cli *cli)
{
	int		mid_flag;

	mid_flag = 0;
	check_for_ctrl_c(cli);
	tputs(tgetstr(ENT_INS_MODE, NULL), 0, ft_putcchar);
	ft_putstr_fd(c, 0);
	check_for_realloc(cli);
	if (chk_if_crs_in_mid(cli, &mid_flag))
		ins_in_middle_of_cmdl(c, cli);
	else
		ft_strcat(CMD, c);
	if (CRS.col < CRS.w_cols - 1)
		CRS.col += 1;
	else
	{
		tputs(tgetstr(MV_DOWN, NULL), 0, ft_putcchar);
		CRS.col = 0;
		CRS.row += 1;
	}
	global_rows_update(cli);
	tputs(tgetstr(LEAVE_INS_MODE, NULL), 0, ft_putcchar);
	refresh_cli(cli);
}
