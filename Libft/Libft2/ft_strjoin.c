/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:19:32 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/04 12:40:03 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		alloc_len;
	int		idx;
	int		s1_len;

	alloc_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s1_len = ft_strlen(s1);
	if (!(new = (char *)malloc(alloc_len * sizeof(char))))
		return (NULL);
	idx = 0;
	while (idx < alloc_len - 1)
	{
		new[idx] = (idx < s1_len ? *s1++ : *s2++);
		idx++;
	}
	new[idx] = 0;
	return (new);
}
