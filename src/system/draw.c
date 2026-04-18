/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:47 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/28 09:42:12 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	apply_texture_column(int index[2], t_cube *get, t_texture *img,
		t_ray *ray)
{
	t_data	*texture;
	int		get_offset;
	int		tex_offset;
	int		texture_height;

	texture = &get->texture[img->texdir];
	get_offset = get->data.line_length / 4;
	tex_offset = texture->line_length / 4;
	texture_height = texture->height;
	while (index[1] <= ray->drawend && index[1] < HEIGHT)
	{
		img->texy = (int)img->texpos;
		if (img->texy < 0)
			img->texy = 0;
		else if (img->texy >= texture_height)
			img->texy = texture_height - 1;
		img->texpos += img->step;
		if (index[0] >= 0 && index[0] < WIDTH)
		{
			get->data.addr[index[1] * get_offset
				+ index[0]] = texture->addr[img->texy * tex_offset + img->texx];
		}
		index[1]++;
	}
}

void    prepare_texture_render(t_cube *get, int x)
{
    t_ray       *ray;
    t_texture   *img;
    int         index[2];
    int         true_wall_top;

    ray = &get->ray;
    img = &get->img;
    index[0] = x;
    index[1] = ray->drawstart;
    genr_textur(get, img, ray);
    if ((ray->side == 0 && ray->raydirx > 0) || (ray->side == 1
            && ray->raydiry < 0))
        img->texx = get->texture[img->texdir].width - img->texx - 1;

    // Vrai haut géométrique du mur sur l'écran (AVEC pitch et jump, sans clamp)
    true_wall_top = HEIGHT / 2 - ray->lineheight / 2
        - (int)(get->player.pitch * HEIGHT / 2)
        + (int)(get->player.pos_z / ray->perpwalldist);

    // Pixels sautés entre le vrai haut et drawstart (à cause du clamp)
    img->texpos = 0;
    if (ray->drawstart > true_wall_top)
        img->texpos = (double)(ray->drawstart - true_wall_top) * img->step;

    apply_texture_column(index, get, img, ray);
}

static void	draw_cond(int draw[2], t_cube *get, int index)
{
	if (draw[0] <= draw[1] && draw[0] >= 0 && draw[1] < HEIGHT)
		prepare_texture_render(get, index);
}

int	render_wall_column(t_cube *get, int index)
{
	int	j;
	int	draw[2];
	int	line_offset;
	int	color_ceiling;
	int	color_floor;

	if (!get->data.addr)
		return (1);
	draw[0] = get->ray.drawstart;
	draw[1] = get->ray.drawend;
	line_offset = get->data.line_length / 4;
	color_ceiling = get->path.p_c;
	color_floor = get->path.p_f;
	j = -1;
	while (++j < draw[0])
	{
		if (j < 0 || j >= HEIGHT || index < 0 || index >= line_offset)
			return (1);
		get->data.addr[j * line_offset + index] = color_ceiling;
	}
	draw_cond(draw, get, index);
	j = draw[1];
	while (++j < HEIGHT)
	{
		if (j >= 0 && j < HEIGHT && index >= 0 && index < line_offset)
			get->data.addr[j * line_offset + index] = color_floor;
	}
	return (0);
}

void	display_stamina(t_cube *cube)
{
	int		x;
	int		y;
	int		bar_width;
	int		bar_height;
	int		stamina_percent;
	int		i;

	stamina_percent = (int)(cube->player.stamina);
	bar_width = 200;
	bar_height = 20;
	x = 10;
	y = 10;
	for (int dy = 0; dy < bar_height; dy++)
	{
		for (int dx = 0; dx < bar_width; dx++)
		{
			if (x + dx < WIDTH && y + dy < HEIGHT)
			{
				int pixel_pos = (y + dy) * (cube->data.line_length / 4) + (x + dx);
				if (pixel_pos >= 0 && pixel_pos < WIDTH * HEIGHT)
					cube->data.addr[pixel_pos] = 0x800000;
			}
		}
	}
	int fill_width = (stamina_percent * bar_width) / 100;
	for (int dy = 2; dy < bar_height - 2; dy++)
	{
		for (int dx = 2; dx < fill_width - 2; dx++)
		{
			if (x + dx < WIDTH && y + dy < HEIGHT)
			{
				int pixel_pos = (y + dy) * (cube->data.line_length / 4) + (x + dx);
				if (pixel_pos >= 0 && pixel_pos < WIDTH * HEIGHT)
				{
					if (stamina_percent > 30)
						cube->data.addr[pixel_pos] = 0x00FF00; // Green
					else if (stamina_percent > 10)
						cube->data.addr[pixel_pos] = 0xFFFF00; // Yellow
					else
						cube->data.addr[pixel_pos] = 0xFF0000; // Red
				}
			}
		}
	}
	for (int dy = 0; dy < bar_height; dy++)
	{
		for (int dx = 0; dx < bar_width; dx++)
		{
			if (dy == 0 || dy == bar_height - 1 || dx == 0 || dx == bar_width - 1)
			{
				if (x + dx < WIDTH && y + dy < HEIGHT)
				{
					int pixel_pos = (y + dy) * (cube->data.line_length / 4) + (x + dx);
					if (pixel_pos >= 0 && pixel_pos < WIDTH * HEIGHT)
						cube->data.addr[pixel_pos] = 0xFFFFFF; // White border
				}
			}
		}
	}
	char *stamina_str = ft_itoa(stamina_percent);
	if (stamina_str)
	{
		int text_x = x + bar_width + 10;
		int text_y = y + 2;
		i = 0;
		while (stamina_str[i])
		{
			if (text_x + 6 < WIDTH && text_y + 12 < HEIGHT)
			{
				for (int dy = 0; dy < 12; dy++)
				{
					for (int dx = 0; dx < 6; dx++)
					{
						if (text_x + dx < WIDTH && text_y + dy < HEIGHT)
						{
							int pixel_pos = (text_y + dy) * (cube->data.line_length / 4) + (text_x + dx);
							if (pixel_pos >= 0 && pixel_pos < WIDTH * HEIGHT)
								cube->data.addr[pixel_pos] = 0xFFFFFF; // White text
						}
					}
				}
				text_x += 7;
			}
			i++;
		}
		free(stamina_str);
	}
}
