/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:27:11 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/10 01:19:54 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
