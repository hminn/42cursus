/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:20:29 by hyeokim           #+#    #+#             */
/*   Updated: 2021/02/16 22:20:32 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (*(s1 + i) == *(s2 + i))
    {
        if (*(s1 + i) == 0 && *(s2 + i) == 0)
            return (0);
        i++;
    }
    return (*(s1 + i) - *(s2 + i));
}

int main(void)
{
	int h = ft_strcmp("", "");
	int c = strcmp("", "");

	printf("h = %d, c = %d\n", h, c);
	return (0);
}