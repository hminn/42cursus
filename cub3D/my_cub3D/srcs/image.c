/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:12:23 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 17:07:00 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		pixel_put_to_image(int color, int x, int y, t_img *img)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->data[y * img->size_l + x * img->bpp / 8] = r;
	img->data[y * img->size_l + x * img->bpp / 8 + 1] = g;
	img->data[y * img->size_l + x * img->bpp / 8 + 2] = b;
}

void		ver_line_color_image(t_line *line, t_info *info, int color)
{
	int y;
	int y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_put_to_image(color, line->x, y, info->img);
			y++;
		}
	}
}

static void	texture_on_img(t_line *line, t_img *tex, t_info *info, t_ray *ray)
{
	int d;

	d = line->y * tex->size_l -
		(info->config.res[Y] * info->config.player.cam_height) *
		tex->size_l / 2 + ray->line_height * tex->size_l / 2;
	line->tex_y = ((d * tex->height) / ray->line_height) / tex->size_l;
	info->img->data[line->y * info->img->size_l + line->x
					* info->img->bpp / 8] = tex->data[line->tex_y
					* tex->size_l + line->tex_x * (tex->bpp / 8)];
	info->img->data[line->y * info->img->size_l + line->x
					* info->img->bpp / 8 + 1] = tex->data[line->tex_y
					* tex->size_l + line->tex_x * (tex->bpp / 8)
					+ 1];
	info->img->data[line->y * info->img->size_l + line->x
					* info->img->bpp / 8 + 2] = tex->data[line->tex_y
					* tex->size_l + line->tex_x * (tex->bpp / 8)
					+ 2];
}

void		ver_line_texture_image(t_line *l, t_info *g, t_img *t, t_ray *r)
{
	int y_max;

	if (l->y0 < l->y1)
	{
		l->y = l->y0;
		y_max = l->y1;
	}
	else
	{
		l->y = l->y1;
		y_max = l->y0;
	}
	if (l->y >= 0)
	{
		while (l->y < y_max)
		{
			texture_on_img(l, t, g, r);
			l->y++;
		}
	}
}

t_img		*new_image(t_info *info, int x, int y)
{
	t_img *img;

	if (!(img = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed");
	ft_bzero(img, sizeof(t_img));
	if (!(img->img = mlx_new_image(info->mlx, x, y)))
		exit_program("Memory allocation failed");
	img->data = mlx_get_data_addr(img->img, &img->bpp,
				&img->size_l, &img->endian);
	img->width = x;
	img->height = y;
	return (img);
}
