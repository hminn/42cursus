/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:48:33 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/03 16:57:17 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	if (0 < nb)
	{
		while (nb != 0)
			result *= nb--;
	}
	else if (nb < 0)
		return (0);
	return (result);
}
