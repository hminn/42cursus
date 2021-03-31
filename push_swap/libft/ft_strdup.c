/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:26:42 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/01 23:32:17 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*pointer;
	int		index;

	if (!(pointer = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	index = 0;
	while (src[index])
	{
		pointer[index] = src[index];
		index++;
	}
	pointer[ft_strlen(src)] = 0;
	return (pointer);
}
