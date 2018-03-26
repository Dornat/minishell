/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:15:38 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/26 19:33:40 by dpolosuk         ###   ########.fr       */
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

static void		find_exec_in_pth(t_cli *cli)
{
	char				**d;
	int					i;
	DIR					*dp;
	struct dirent		*ds;

	if (path_exist(cli) == 0)
		return ;
	if (!(d = ft_strsplit(EPTH + 5, ':')))
		return ;
	i = 0;
	while (d[i])
	{
		if ((dp = opendir(d[i])) == NULL)
			return ;
		while ((ds = readdir(dp)) != NULL)
		{
			if (!ft_strncmp(CMD, ds->d_name, ft_strlen(CMD)))
			{
				ft_bzero(CMD, ft_strlen(CMD));
				ft_strcat(CMD, ds->d_name);
				CRS.col = ft_strlen(PRT.p) + ft_strlen(CMD);
				refresh_cli(cli);
				closedir(dp);
				free_double_ptr(&d);
				return ;
			}
		}
		closedir(dp);
		i++;
	}
}

void			basic_tab_compl(t_cli *cli)
{
	int			i;

	i = 0;
	if (CMD[0] == '\0')
		return ;
	while (BIS[i])
	{
		if (!ft_strncmp(CMD, BIS[i], ft_strlen(CMD)))
		{
			ft_bzero(CMD, ft_strlen(CMD));
			ft_strcat(CMD, BIS[i]);
			CRS.col = ft_strlen(PRT.p) + ft_strlen(CMD);
			refresh_cli(cli);
			return ;
		}
		i++;
	}
	find_exec_in_pth(cli);
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
	else if (!ft_strcmp(c, CTRL_E))
	{
		printf("CMD: %s\n", CMD);
	}
	return (0);
}
