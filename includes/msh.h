/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:08:10 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/03/26 19:32:13 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <stdio.h>
# include <dirent.h>
# include <libft.h>

/*
** Max buffer for termtype according to convention (from termcap man)
*/

# define CONV_MAX_BUFF 2048

# define PATH_LEN 256
# define CMD_LEN 256

/*
** Defines for capabilities in termcap
*/

# define MV_LEFT			"le"
# define MV_RIGHT			"nd"
# define MV_DOWN			"do"
# define MV_UP				"up"
# define MV_BEG				"cr"
# define DEL_CHR			"dc"
# define ENT_INS_MODE		"im"
# define LEAVE_INS_MODE		"ei"
# define ENT_STOUT_MODE		"so"
# define LEAVE_STOUT_MODE	"se"
# define CLEAR_SCREEN		"cd"
# define SAVE_CRS_POS		"sc"
# define RESTR_CRS_POS		"rc"

/*
** Defines for keys
*/

# define LEFT_ARROW		"\e[D"
# define RIGHT_ARROW	"\e[C"
# define CTRL_A			"\x01"
# define CTRL_B			"\x02"
# define CTRL_C			"\x03"
# define CTRL_D			"\x04"
# define CTRL_E			"\x05"
# define CTRL_F			"\x06"
# define DEL_KEY		"\x7f"
# define ENTER_KEY		"\n"
# define TAB_KEY		"\t"

/*
** Struct for saving cursor position and terminal resolution
*/

typedef struct		s_cpos
{
	int		w_cols;
	int		w_rows;
	int		col;
	int		row;
	int		grows;
}					t_cpos;

/*
** Struct for prompt
*/

typedef struct		s_prmt
{
	char	*p;
	char	*tp;
	int		len;
}					t_prmt;

/*
** Struct for command line interface, which includes other structs
*/

typedef struct		s_cli
{
	t_cpos			crs;
	t_prmt			prt;
	char			*cmd;
	char			*tcmd;
	unsigned int	bs;
	char			**cmds;
	int				cmds_i;
	char			**acmd;
	unsigned int	brk:1;
	unsigned int	dqt:1;
	t_list			*env;
	char			*epth;
	char			*pth;
	enum			e_bi
	{
		ext, cd, env, setnv, unsetnv, ech
	}				t_bi;
	unsigned int	bi_flag:1;
	char			**bis;
}					t_cli;

/*
** Defines for t_cli struct
** CRS - cursor struct
** PRT - prompt struct
** CMD - current command in the prompt
** TMP - saved command for dealing with quoting
** BS - for saving cursor position globally when dealing with quoting
** ACMD - splitted CMD
** ENV - copy of environ
** EPTH - saved path from environ (after PATH=)
** PTH - temp path saved from environ PATH to find executable
** BI - builtin enum struct
** BIF - flag for checking if user entered builtin program
*/

# define CRS cli->crs
# define PRT cli->prt
# define CMD cli->cmd
# define TMP cli->tcmd
# define BS cli->bs
# define CMDS cli->cmds
# define I cli->cmds_i
# define ACMD cli->acmd
# define ENV cli->env
# define EPTH cli->epth
# define PTH cli->pth
# define BI cli->t_bi
# define BIF cli->bi_flag
# define BIS cli->bis

/*
** Main functions
*/

void				init_term_data(t_cli *cli);
void				enable_raw_mode(void);
void				disable_raw_mode(void);
t_list				*copy_env(void);
void				init_cpos(t_cli *cli);

/*
** Key process functions
*/

int					key_process(char *c, t_cli *cli);
void				insert_chr_in_cmdl(char *c, t_cli *cli);
void				del_chr_from_cmdl(t_cli *cli);

int					ent_key_processing(t_cli *cli);
int					parse_qt_bs(char *s, int i, t_cli *cli);
int					parse_qt_are_there_null(char *s, int i, t_cli *cli);

void				refresh_cli(t_cli *cli);
void				reset_crs(t_cli *cli);

/*
** Parse cmd functions
*/

char				**split_semicol(char *s);
char				**msh_split(char *s, t_cli *cli);
int					msh_split_arg_num(char *s);
int					parse_cmd(t_cli *cli);
int					parse_quote(char *s, int i);
int					parse_dquote(char *s, int i);

/*
** Execution of external programs
*/

void				exec_prog(t_cli *cli);
int					path_exist(t_cli *cli);

/*
** Execution of builtins
*/

void				exec_builtin(t_cli *cli);
void				bi_exit(t_cli *cli);
void				bi_setenv(t_cli *cli);
t_list				*bi_find_env(t_list *env, char *arg);
void				bi_unsetenv(t_cli *cli);
void				bi_cd(t_cli *cli);

/*
** Misc functions
*/

int					ft_isnotprint(int c);
int					ft_putcchar(int c);
int					peekb(char c, char *s);
int					lcins(char c, char *s);
void				free_double_ptr(char ***s);

#endif
