/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:35:27 by hyeokim           #+#    #+#             */
/*   Updated: 2020/09/18 20:04:45 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int		ft_putstrprec(char *str, int prec)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
		ft_putchar(str[char_count++]);
	return (char_count);
}
