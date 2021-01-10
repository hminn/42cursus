/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isispace_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:52:45 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/10 14:53:31 by hyeokim          ###   ########.fr       */
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
