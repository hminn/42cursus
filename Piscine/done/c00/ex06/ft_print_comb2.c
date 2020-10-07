/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:20:18 by hyeokim           #+#    #+#             */
/*   Updated: 2020/01/25 17:41:00 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(char c1, char c2, char c3, char c4)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, " ", 1);
	write(1, &c3, 1);
	write(1, &c4, 1);
}

void	ft_print_comma(char c1, char c2)
{
	if (c1 != '9' || c2 != '8')
	{
		write(1, ", ", 2);
	}
}

char	ft_judge(char n0, char n1, char n2, char n3)
{
	char c;

	if (n3 == '\0' || (n0 == n2 && n1 < n3))
	{
		c = n1 + 1;
	}
	else
	{
		c = '0';
	}
	return (c);
}

void	ft_print_comb2(void)
{
	char n[4];

	n[0] = '0';
	n[3] = '\0';
	while (n[0] <= '9')
	{
		n[1] = '0';
		while (n[1] <= '9')
		{
			n[2] = n[0];
			while (n[2] <= '9')
			{
				n[3] = ft_judge(n[0], n[1], n[2], n[3]);
				while (n[3] <= '9')
				{
					ft_print_num(n[0], n[1], n[2], n[3]);
					ft_print_comma(n[0], n[1]);
					n[3]++;
				}
				n[2]++;
			}
			n[1]++;
		}
		n[0]++;
	}
}
