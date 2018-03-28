/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:15:38 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 11:27:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static int		crs_chk_mv_right(char *c, t_cli *cli)
{
	int		ptr;

	ptr = 0;
	if (CRS.row > 0)
		ptr = CRS.row * CRS.w_cols + CRS.col;
	else
		ptr = CRS.col;
	if ((ptr < (int)ft_strlen(cli->cmd) + PRT.len) &&
		(!ft_strcmp(c, RIGHT_ARROW) || !ft_strcmp(c, CTRL_F)))
		return (1);
	return (0);
}

static int		crs_chk_mv_left(char *c, t_cli *cli)
{
	if ((CRS.row || (!CRS.row && CRS.col > PRT.len)) &&
		(!ft_strcmp(c, LEFT_ARROW) || !ft_strcmp(c, CTRL_B)))
		return (1);
	return (0);
}

static int		crs_chk_del(char *c, t_cli *cli)
{
	if ((CRS.row || (!CRS.row && CRS.col > PRT.len)) &&
		(!ft_strcmp(c, DEL_KEY)))
		return (1);
	return (0);
}

int				key_process(char *c, t_cli *cli)
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
		return (ent_key_processing(cli));
	else if (!ft_strcmp(c, CTRL_D) && ft_strcmp(PRT.p, "> "))
	{
		ft_putstr("exit\n");
		bi_exit(cli);
	}
	else if (!ft_strcmp(c, TAB_KEY))
		basic_tab_compl(cli);
	return (0);
}
