/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:16:01 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/08 13:08:24 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	size_t			i;
	char			*new;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)value;
	new = (char *)ptr;
	while (i < size)
	{
		new[i] = chr;
		i++;
	}
	return (ptr);
}
