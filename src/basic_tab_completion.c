/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tab_completion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:41:29 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/28 10:52:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

static void		find_exec_int_pth_whif(t_cli *cli, DIR *dp, struct dirent *ds,
										char **d)
{
	ft_bzero(CMD, ft_strlen(CMD));
	ft_strcat(CMD, ds->d_name);
	ft_strcat(CMD, " ");
	CRS.col = PRT.len + ft_strlen(CMD);
	refresh_cli(cli);
	closedir(dp);
	free_double_ptr(&d);
}

static void		find_exec_in_pth(t_cli *cli, int i)
{
	char				**d;
	DIR					*dp;
	struct dirent		*ds;

	if (path_exist(cli) == 0)
		return ;
	if ((d = ft_strsplit(EPTH + 5, ':')) == NULL)
		return ;
	while (d[i])
	{
		if ((dp = opendir(d[i])) == NULL)
		{
			free_double_ptr(&d);
			return ;
		}
		while ((ds = readdir(dp)) != NULL)
		{
			if (!ft_strncmp(CMD, ds->d_name, ft_strlen(CMD)))
				return (find_exec_int_pth_whif(cli, dp, ds, d));
		}
		closedir(dp);
		i++;
	}
	free_double_ptr(&d);
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
			ft_strcat(CMD, " ");
			CRS.col = PRT.len + ft_strlen(CMD);
			refresh_cli(cli);
			return ;
		}
		i++;
	}
	find_exec_in_pth(cli, 0);
}
