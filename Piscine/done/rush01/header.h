/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:48:50 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 16:49:07 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

int		ft_promise_col(int (*g_board)[6], int row);
int		ft_promise_row(int (*g_board)[6], int col);
int		ft_promise(int (*g_board)[6], int row, int col, int value);
int		puzzle(int (*g_board)[6], int row, int col, int flag);
int		ft_str_check(char *str);
void	ft_input_board(int (*board)[6], char *str);
#endif
