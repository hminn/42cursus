/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:09:23 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 16:53:01 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	determine_side_draw(t_ray *r, t_info *g, t_line *l, double wall_x)
{
	t_img	*img;
	int		tex_x;

	img = g->tex[TEX_WE];
	if (r->side == 1)
		img = g->tex[TEX_EA];
	if (r->side == 2)
		img = g->tex[TEX_SO];
	if (r->side == 3)
		img = g->tex[TEX_NO];
	tex_x = (int)(wall_x * (double)img->width);
	if ((r->side == 0 || r->side == 1) && r->ray_dir.x > 0)
		tex_x = img->width - tex_x - 1;
	if ((r->side == 2 || r->side == 3) && r->ray_dir.y < 0)
		tex_x = img->width - tex_x - 1;
	l->y0 = r->draw_end;
	l->y1 = r->draw_start;
	l->tex_x = tex_x;
	ver_line_texture_image(l, g, img, r);
}

void		texturisation(t_ray *ray, t_info *info)
{
	t_img	*img;
	t_line	*line;
	double	wall_x;

	if (!(line = malloc(sizeof(t_line))))
		exit_program("Memory allocation failed");
	ft_bzero(line, sizeof(t_line));
	line->x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		wall_x = info->config.player.pos.y
				+ ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall_x = info->config.player.pos.x
				+ ray->perp_wall_dist * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	if (info->config.map[ray->map.y][ray->map.x] == '1')
		determine_side_draw(ray, info, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	ver_line_color_image(line, info, info->config.color[COLOR_C]);
	line->y0 = info->config.res[Y];
	line->y1 = ray->draw_end;
	ver_line_color_image(line, info, info->config.color[COLOR_F]);
	free(line);
}
