/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:42:06 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/04 10:59:04 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_sqrt(int nb)
{
	long long	j;

	j = 0;
	while ((j * j) <= nb)
		j++;
	return (j - 1);
}

int		ft_is_prime(int nb)
{
	int		i;
	int		sqrt;

	i = 2;
	if (nb < 2)
		return (0);
	else if (2 < nb)
	{
		sqrt = ft_find_sqrt(nb);
		while (i <= sqrt)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}
