/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:12:41 by hyeokim           #+#    #+#             */
/*   Updated: 2020/01/27 22:56:27 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*chg;

	chg = dest;
	while (1)
	{
		*chg++ = *src++;
		if (*(src - 1) == '\0')
			break ;
	}
	return (dest);
}
