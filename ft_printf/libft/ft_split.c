/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:15:30 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/07 17:06:02 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_count(char const *str, char c)
{
	int		index;
	int		cnt;

	index = 0;
	cnt = 1;
	while (str[index])
	{
		if (str[index] == c)
		{
			if (index == 0)
				cnt--;
			else if (str[index + 1] == 0)
				break ;
			if (!(str[index + 1] == c))
				cnt++;
		}
		index++;
	}
	return (cnt);
}

void	ft_len_count(char const *str, char c, int *array)
{
	int		index;
	int		cnt;

	index = 0;
	cnt = 0;
	while (1)
	{
		if (!(*str == c) && *str != 0)
			cnt++;
		else if (*str == c || *str == 0)
		{
			if (index == 0 && cnt == 0 && *str != 0)
			{
				str++;
				continue ;
			}
			else if (!(*(str - 1) == c))
				array[index++] = cnt + 1;
			if (*str == 0)
				break ;
			cnt = 0;
		}
		str++;
	}
}

void	ft_input(char const *str, char c, int *len_array, char **result)
{
	int		index;
	int		loop;
	int		word_ind;

	index = 0;
	loop = ft_word_count(str, c);
	while (index < loop)
	{
		word_ind = 0;
		if (!(*str == c))
		{
			result[index] = (char *)malloc(sizeof(char) * len_array[index]);
			while ((len_array[index] - 1) > 0)
			{
				result[index][word_ind++] = *str++;
				len_array[index]--;
			}
			result[index][word_ind] = 0;
			index++;
		}
		else
			str++;
	}
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		*len_array;
	int		word_cnt;

	word_cnt = ft_word_count(str, c);
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	len_array = (int *)malloc(sizeof(int) * word_cnt);
	ft_len_count(str, c, len_array);
	ft_input(str, c, len_array, result);
	free(len_array);
	result[word_cnt] = 0;
	return (result);
}
