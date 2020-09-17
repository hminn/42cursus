/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:16:01 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/01 22:50:38 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	char	*new;

	new = ptr;
	while (size--)
	{
		if (*new == 0)
		{
			*new = value;
			break ;
		}
		*new++ = value;
	}
	return (ptr);
}
