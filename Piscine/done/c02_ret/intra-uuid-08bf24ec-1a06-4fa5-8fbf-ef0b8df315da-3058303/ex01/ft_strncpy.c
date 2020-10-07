/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:18:11 by hyeokim           #+#    #+#             */
/*   Updated: 2020/01/28 10:36:36 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*chg;
	unsigned int	i;

	chg = dest;
	i = 0;
	while (i < n)
	{
		if (*src == '\0')
		{
			while (i++ < n)
			{
				*chg++ = '\0';
			}
			break ;
		}
		else
		{
			*chg++ = *src++;
		}
		i++;
	}
	return (dest);
}
