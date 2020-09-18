/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 02:41:25 by hyeokim           #+#    #+#             */
/*   Updated: 2020/09/19 04:02:04 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->align = 0;
	info->zero = 0;
	info->dot = 0;
	info->prec = 0;
	info->spec = 0;
	info->data_len = 0;
}

void		control_center(va_list ap, char *str, t_info *info)
{
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			parse_flags(&str, info);
			parse_width(ap, &str, info);
			parse_precision(ap, &str, info);
			parse_specifier(&str, info);
			print_hub(ap, info);
			init_info(info);
		}
	}
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	t_info	*info;
	int		printed_len;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	init_info(info);
	info->printed_len = 0;
	va_start(ap, str);
	control_center(ap, (char *)str, info);
	printed_len = info->printed_len;
	init_info(info);
	free(info);
	va_end(ap);
	return (printed_len);
}
