/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:48:14 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/10 10:28:03 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*g_convert[101] = {0, };
char	*g_llion[13] = {0, };

int		ft_alloc_len(char *str)
{
	int	alloc_len;

	alloc_len = (ft_strlen(str) / 3);
	alloc_len += (ft_strlen(str) % 3 != 0 ? 1 : 0);
	return (alloc_len);
}

int		main(int argc, char *argv[])
{
	char		*ptr;
	char		*str;
	t_numbers	*number_strct;

	if (ft_error(argc, argv))
		return (0);
	if (argc == 3)
	{
		ptr = ft_read_dict(argv[1]);
		str = argv[2];
	}
	else
	{
		ptr = ft_read_dict("numbers.dict.txt");
		str = (argc == 2 ? argv[1] : 0);
	}
	ft_parse_dict(ptr);
	number_strct = (t_numbers *)malloc(sizeof(t_numbers) * (ft_alloc_len(str)));
	ft_strctlz(number_strct, str, ft_alloc_len(str));
	ft_print(number_strct, ft_alloc_len(str));
	free(number_strct);
	return (0);
}
