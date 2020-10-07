/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:21:51 by hyeokim           #+#    #+#             */
/*   Updated: 2020/01/29 11:07:12 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_count_len(char *str)
{
	int i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*chg;
	int		result;

	chg = dest;
	result = ft_count_len(src);
	while (size--)
	{
		if ((*chg++ = *src++) != 0)
		{
			if ((size == 0) && (*(chg - 1) != 0))
			{
				*(chg - 1) = 0;
			}
		}
	}
	return (result);
}
