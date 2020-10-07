/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:42:23 by hyeokim           #+#    #+#             */
/*   Updated: 2020/01/26 22:10:55 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive(char pre)
{
	char	post;
	
	post = pre + 1;
	while (post <= '9')
	{
		write(1, &pre, 1);
		write(1, &post, 1);
		write(1, ", ", 2);
		post++;
	}
}

void	ft_print_combn(int nb)
{
	char	a;

	a = '0';
	while (a <= ':' - nb)
	{
		ft_recursive(a);
		a++;		
	}
}

void	ft_print_combn(int nb)
{
	char	a;
	int		i;

	i = 0;
	a = '0';
	while (a < ':' - nb)
	{
		while (i < nb)
		{
			if (i <= 

			
