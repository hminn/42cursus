/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:42:57 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 19:42:59 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace_str(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		if (ft_isspace(str[idx]))
			idx++;
		else
			return (0);
	}
	return (1);
}
