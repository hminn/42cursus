/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:45:48 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/09 22:41:25 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HEADER_H
#	define HEADER_H
#	include <fcntl.h>
#	include <unistd.h>
#	include <stdlib.h>

typedef	struct s_numbers	t_numbers;

struct	s_numbers{
	int third;
	int	second;
	int	first;
};

int		ft_strlen(char *str);
int		ft_judge_special(t_numbers *number_strct, int index, int flag);
int		ft_non_number(char *str);
int		ft_error(int argc, char *argv[]);
char	*ft_read_dict(const char *file);
char	*ft_putcvt(char *contents);
char	*ft_check_non_llion(char *contents);
char	*ft_putllion(char *contents);
void	ft_putchar(char *str);
void	ft_parse_dict(char *contents);
void	ft_judge_space(t_numbers *number_strct, int index, int flag);
void	ft_str_to_intarr(int *int_arr, char *input, int alloc_len);
void	ft_to_struct(t_numbers *n_struct, int *int_arr, int alloc_len);
void	ft_strctlz(t_numbers *number_strct, char *input, int alloc_len);
void	ft_flag_print(t_numbers *number_strct, int number, int index, int flag);
void	ft_print(t_numbers *number_strct, int alloc_len);
#	endif
