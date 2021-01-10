/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:31:24 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 21:48:05 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# define INIT	-1
# define QUOTE	39
# define DQUOTE	34
# define ETC	42
# define LREDIR	62
# define DREDIR	6
# define RREDIR	60

int				g_exit_value;
char			**g_envp;
char			*g_env_user;

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

typedef struct	s_quote
{
	int			type;
	int			start;
	int			end;
}				t_quote;

typedef struct	s_redir
{
	int			argc;
	char		**argv;
	char		**cmds;
	char		*types;
}				t_redir;

typedef struct	s_pipe
{
	char		*line;
	char		**argv;
}				t_pipe;

/*
**	main.c
*/
void			save_envp(int argc, char **argv, char **envp, t_list **envs);
void			catch_signal(void);

/*
**	handle_signal.c
*/
void			handle_signal(int signo);

/*
**	print_prompt.c
*/
int				preprocess_input(char **line);
void			print_front(char *tmp, char *set, char *pwd, char*user);
void			print_prompt(char *user);

/*
**	parse_line.c
*/
char			**parse_line(char *line);
int				check_error(char *line);

/*
**	get_argv.c
*/
char			*change_argv(char *str, t_list *envs);
char			**get_argv(char *line, t_list *envs);

/*
**	func_etc.c
*/
int				ft_puterror_fd(char *s1, char *s2, int fd);
void			free_double_arr(char **arr);
void 			free_pipe(t_pipe *p);

/*
**	utils_env.c
*/
int				is_valid_for_env(char *arg);
int				is_valid_for_export(char *arg);
int				is_exist_key(char *key, t_list *envs);
char			*get_value(char *key, t_list *envs);
char			*find_path(char *argv, t_list *envs);

/*
**	utils_export.c
*/
char			**convert_lst_to_arr(t_list *lst);
void			sort_double_arr(char **arr);
void			modify_env_for_export(char **arr);
void			print_double_arr(char **arr);

/*
**	func_check.c
*/
int				check_quote(char *str);
int				check_env(char *str);
int				check_pipe(char *str);
int				check_redirect_type(char *line, int i);
int				check_redirect(char *line);

/*
**	func_redirect.c
*/
int				redir_error_check(char *str);
int				return_redirect(t_redir *redir, int j);

/*
**	func_parse.c
*/
char			*parse_env(char *argv, t_list *envs);
char			*parse_quote(char *argv, t_list *envs);

/*
**	run_etc.c
*/
void			run_pwd(void);
void			run_echo(char **argv);

/*
**	run_cd.c
*/
void			run_cd(char **argv, t_list *envs);
void			check_path(char *argv, char *path);

/*
**	run_exit.c
*/
void			run_exit(char **argv);

/*
**	run_env.c
*/
void			run_env(char **argv, t_list *envs);

/*
**	run_export.c
*/
void			run_export(char **argv, t_list *envs);

/*
**	run_unset.c
*/
void			run_unset(char **argv, t_list *envs);

/*
**	exec_redirect.c
*/
char			*preprocess_line(char *line, int start, int num, char *charset);
void			cmd_redirect(t_redir *r, t_list *envs);

/*
**	run_redirect.c
*/
int				parse_redirect(char *line, t_redir *redir);
void			init_redirect(char *line, t_redir *redir);
void			open_files(t_redir *r);
void			run_redirect(char *line, t_list *envs);

/*
**	run_pipe.c
*/
void			close_fd(int fd[2]);
void			parse_pipe(char **line, t_pipe *p, t_list *envs);
void			prev_pipe(int child, int fd[2], t_list *envs, t_pipe p);
void			next_pipe(int child, int fd[2], t_list *envs, char *line);
void			run_pipe(char *line, t_list *envs);

/*
**	exec_cmds.c
*/
int				run_base(char *line, t_list *envs);
void			command_unregistered(char *line, t_list *envs);
void			run_cmds(char *line, t_list *envs);

#endif
