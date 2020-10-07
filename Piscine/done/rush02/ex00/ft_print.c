/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:36:51 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/09 20:47:50 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern char	*g_convert[101];
extern char	*g_llion[13];

void	ft_judge_space(t_numbers *number_strct, int index, int flag)
{
	int		space;
	int		check;

	space = 0;
	check = index;
	while (check >= 0)
	{
		if ((flag > 1 || index > check) && number_strct[check].first != 0)
			space = 1;
		if ((flag > 2 || index > check) && number_strct[check].second != 0)
			space = 1;
		if ((index > check) && number_strct[check].third != 0)
			space = 1;
		check--;
	}
	if (space)
		ft_putchar(" ");
}

int		ft_judge_special(t_numbers *number_strct, int index, int flag)
{
	int		space;
	int		check;

	space = 0;
	check = index;
	while (check >= 0)
	{
		if ((flag > 1 || index > check) && number_strct[check].first != 0)
			space = 1;
		if ((flag > 2 || index > check) && number_strct[check].second != 0)
			space = 1;
		if ((index > check) && number_strct[check].third != 0)
			space = 1;
		check--;
	}
	if (space == 0 && index >= 1)
		return (1);
	return (0);
}

void	ft_flag_print(t_numbers *number_strct, int number, int index, int flag)
{
	if (number != 0)
	{
		if (flag == 3)
		{
			ft_putchar(g_convert[number]);
			ft_putchar(" ");
			ft_putchar(g_convert[100]);
		}
		else
			ft_putchar(g_convert[number]);
		ft_judge_space(number_strct, index, flag);
	}
}

void	ft_print(t_numbers *number_strct, int alloc_len)
{
	int		index;

	index = alloc_len - 1;
	while (index >= 0)
	{
		ft_flag_print(number_strct, number_strct[index].third, index, 3);
		ft_flag_print(number_strct, number_strct[index].second, index, 2);
		ft_flag_print(number_strct, number_strct[index].first, index, 1);
		if (number_strct[index].third != 0 ||
			number_strct[index].second != 0 ||
			number_strct[index].first != 0)
		{
			if (ft_judge_special(number_strct, index, 1))
				ft_putchar(" ");
			ft_putchar(g_llion[index]);
			ft_judge_space(number_strct, index, 1);
		}
		index--;
	}
	if (alloc_len == 1 && number_strct[0].third == 0 &&
		number_strct[0].second == 0 && number_strct[0].first == 0)
		ft_putchar(g_convert[0]);
}
