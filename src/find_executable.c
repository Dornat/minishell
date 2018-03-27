/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:39:06 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/27 18:33:01 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh.h>

int				find_executable_with_path(char *pth)
{
	if (access(pth, F_OK) == 0)
	{
		if (access(pth, X_OK) == -1)
			return (-1);
		else
			return (0);
	}
	else
		return (-2);
	return (-2);
}

static int		append_pth_of_exec(t_cli *cli)
{
	if (!ACMD[0])
		return (0);
	ft_strcat(PTH, "/");
	ft_strcat(PTH, ACMD[0]);
	return (find_executable_with_path(PTH));
}

int				find_executable(t_cli *cli)
{
	char	**dr;
	int		i;
	int		ret;

	if (!(dr = ft_strsplit(EPTH + 5, ':')))
		return (0);
	i = 0;
	while (dr[i])
	{
		if (PTH[0] == '\0')
			ft_memcpy(PTH, dr[i], ft_strlen(dr[i]));
		else
		{
			ft_bzero(PTH, ft_strlen(PTH));
			ft_memcpy(PTH, dr[i], ft_strlen(dr[i]));
		}
		if ((ret = append_pth_of_exec(cli)) == 0)
		{
			free_double_ptr(&dr);
			return (ret);
		}
		i++;
	}
	free_double_ptr(&dr);
	return (ret);
}
