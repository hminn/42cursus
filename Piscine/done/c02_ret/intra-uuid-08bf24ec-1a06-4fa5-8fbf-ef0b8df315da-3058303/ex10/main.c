/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:48:18 by hmin              #+#    #+#             */
/*   Updated: 2020/01/29 09:49:55 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include "ft_strlcpy.c"

int		main(void)
{
	char a[10] = "";
	char b[] = " ";
	char a2[10] = "";


	printf("%s / %s /return : %lu \n", a, b, strlcpy(a, b, 2));
	printf("%s / %s /return : %d \n", a2, b, ft_strlcpy(a2, b, 2));
	return (0);
}
