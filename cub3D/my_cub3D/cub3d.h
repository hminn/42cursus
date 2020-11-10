/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:18:25 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 01:26:05 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"

/*
** resolution id list
*/
# define X 0
# define Y 1

/*
** texture id list
*/
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_S 4

/*
** color id list
*/
# define COLOR_F 0
# define COLOR_C 1

/*
** all id list
*/
# define ID_R 0
# define ID_NO 1
# define ID_SO 2
# define ID_WE 3
# define ID_EA 4
# define ID_S 5
# define ID_F 6
# define ID_C 7
# define ID_MAP 8

/*
** mlx key
*/
# define MLX_KEY_PRESS 2
# define MLX_KEY_RELEASE 3
# define MLX_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_R	15
# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2
# define KEY_F 	3
# define KEY_Q	12
# define KEY_E	14
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# define KEY_TAB 48
# define KEY_MINUS 27
# define KEY_PLUS 24

/*
** struct of coordinate
*/
typedef struct		s_coord_db
{
	double			x;
	double			y;
}					t_coord_db;

typedef struct		s_coord_int
{
	int				x;
	int				y;
}					t_coord_int;

/*
// struct of mlx_img information
*/
typedef struct		s_img
{
	void			*img;
	char			*data;
	int				size_l;
	int				endian;
	int				bpp;
	int				width;
	int				height;
}					t_img;

typedef struct		s_line
{
	int				x;
	int				y;
	int				y0;
	int				y1;
	int				tex_x;
	int				tex_y;
}					t_line;

/*
// struct of ray information
*/
typedef struct		s_ray
{
	int				pix;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			camera_x;
	double			perp_wall_dist;
	double			*z_buffer;
	t_coord_int		map;
	t_coord_int		step;
	t_coord_db		ray_dir;
	t_coord_db		side_dist;
	t_coord_db		delta_dist;
}					t_ray;

/*
// struct of sprite information
*/
typedef struct		s_sprite
{
	t_coord_int		coord;
}					t_sprite;

typedef struct		s_sprites
{
	t_coord_int		coord;
	struct s_sprites*next;
}					t_sprites;

typedef struct		s_draw_sprite
{
	int				i;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				stripe;
	int				y;
	int				d;
	int				color;
	int				totcolor; // what is this?
	double			inv_det; // what is this?
	t_sprite		*sprites;
	t_coord_int		draw_start;
	t_coord_int		draw_end;
	t_coord_int		tex;
	t_coord_db		sprite;
	t_coord_db		transform;
}					t_draw_sprite;

/*
// struct of key event information
*/
typedef struct		s_key
{
	int				go;
	int				back;
	int				left;
	int				right;
	int				turn;
	int				cam_up;
	int				cam_down;
	int				rotate_left;
	int				rotate_right;
}					t_key;

/*
// struct of player imformation
*/
typedef struct		s_player
{
	int				id;
	int				count; // cnt
	double			cam_height;
	t_coord_db		pos;
	t_coord_db		dir;
	t_coord_db		plane;
}					t_player;

/*
// struct of map configuration
*/
typedef struct		s_config
{
	int				id[9];
	int				res[2];
	int				color[2];
	int				row;
	int				col;
	int				flag;
	char			*texture[5];
	char			*map_name;
	char			**map;
	t_player		player;
}					t_config;

typedef struct		s_info // s_game
{
	void			*mlx;
	void			*win;
	double			move_speed; // speed_mov
	double			rotate_speed; // speed_rot
	t_image			*img;
	t_image			**tex;
	t_image			*sprite;
	t_sprites		*sprites_on_screen;
	t_key			*key;
	t_config		config;
}					t_info;

#endif
