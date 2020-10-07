/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:16:43 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 23:30:34 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;

	result = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		while (--power != 0)
			result *= nb;
	return (result);
}
