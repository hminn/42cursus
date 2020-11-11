/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:18:25 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 17:28:49 by hyeokim          ###   ########.fr       */
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
# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

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

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	double			speed_mov;
	double			speed_rot;
	t_image			*img;
	t_image			**tex;
	t_image			*sprite;
	t_sprites		*sprites_on_screen;
	t_key			*key;
	t_config		config;
}					t_info;

/*
** exit
*/
void				exit_program(char *str);

/*
** parse
*/
void				parse_hub(int argc, char *argv[], t_info *info);
void				parse_resolution(char *line, t_config *config);
void				parse_texture(char *line, int id, t_config *config);
int					check_texture_id(char *line, t_config *config);
void				parse_color(char *line, int id, t_config *config);
int					check_color_id(char *line, t_config *config);
void				parse_map(int ret, char *line, t_config *config);
void				save_player_info(int row, int col, t_config *config);

/*
** parse utils
*/
int					check_filename_ext(char *filename, char *ext);
void				check_identifiers_exist(int ret, t_config *config);
int					check_valid_chr(char c);

/*
** init
*/
void				init_hub(t_info *info);
void				convert_xpm_to_img(t_info *info);
void				view_debug(t_info *info);

/*
** config key & window
*/
int					key_manager(t_info *info);
int					key_released(int key, void *parameter);
int					key_pressed(int key, void *parameter);
int					exit_window(void *parameter);

/*
** control camera & player
*/
void				move_go(t_info *info);
void				move_back(t_info *info);
void				move_left(t_info *info);
void				move_right(t_info *info);
void				camera_up(t_info *info);
void				camera_down(t_info *info);
void				rotate_left(t_info *info);
void				rotate_right(t_info *info);

/*
** raycasting
*/
int					raycasting(t_info *info);
void				perp_and_height(t_ray *ray, t_player *player, t_info *info);
void				hit(t_ray *ray, t_info *info);

/*
** sprite
*/
int					draw_sprite(t_ray *ray, t_info *info);
void				is_sprite(t_ray *ray, t_info *info);
void				sort_sprite(t_info *info,
								t_sprite *sprites, int nbr_sprites);
t_sprite			*list_to_tab(t_info *info);

/*
** texture
*/
void				texturisation(t_ray *ray, t_info *info);

/*
** image
*/
void				pixel_put_to_image(int color, int x, int y, t_img *img);
void				ver_line_color_image(t_line *line, t_info *info, int color);
void				ver_line_texture_image(t_line *line, t_info *info,
											t_img *tex, t_ray *ray);
t_img				*new_image(t_info *info, int x_len, int y_len);

/*
** srceenshot
*/
void				create_screenshot(t_img *mlx_img, char *name);

#endif
