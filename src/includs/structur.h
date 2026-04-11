/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:33:41 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:06:20 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTUR_H
# define STRUCTUR_H

typedef struct s_text
{
	char			*id;
	char			*path;
	struct s_text	*next;
}					t_text;

typedef struct s_color
{
	char			*c_id;
	char			*color;
	char			*red;
	char			*green;
	char			*blue;
	char			**color_sep;
	struct s_color	*next;
}					t_color;

typedef struct s_par
{
	int				map_line;
	int				height;
	int				width;
	char			**map;
}					t_par;

typedef struct s_file
{
	char			*entry;
	char			**input;
	int				text_i;
	int				col_i;
	struct s_file	*next;
}					t_file;

typedef struct s_camera
{
	double			camerax;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
}					t_camera;

typedef struct s_player
{
	char			start;
	int				dx;
	int				dy;
	double			pos_x;
	double			pos_y;
	double			move;
	double			rotet;
	double			pitch;
}					t_player;

typedef struct s_map
{
	int				map_line;
	char			**map;
}					t_map;

typedef struct s_path
{
	char			*p_no;
	char			*p_so;
	char			*p_ea;
	char			*p_we;
	int				p_f;
	int				p_c;
}					t_path;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_window;

typedef struct s_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_texture;

typedef struct s_ray
{
	double			posx;
	double			posy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				original_drawstart;
	int				texture;
}					t_ray;

typedef struct s_data
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

typedef struct move
{
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				look_up;
	int				look_down;
}					t_move;

typedef struct s_cube
{
	t_player		player;
	t_map			map;
	t_path			path;
	t_data			texture[4];
	t_data			data;
	t_ray			ray;
	t_texture		img;
	t_window		window;
	t_camera		cam;
	t_move			move;
	int				error;
	t_file			*file;
	t_text			*text;
	t_color			*col;
	t_par			maps;
}					t_cube;

#endif