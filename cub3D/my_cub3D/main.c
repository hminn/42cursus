/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:12:52 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/10 01:56:48 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_info		*info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit_program("Memory allocation failed");
	parse_hub(argc, argv, game);
}
