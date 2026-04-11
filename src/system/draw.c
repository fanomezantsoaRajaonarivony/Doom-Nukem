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

    // Vrai haut géométrique du mur sur l'écran (AVEC pitch, sans clamp)
    true_wall_top = HEIGHT / 2 - ray->lineheight / 2
        - (int)(get->player.pitch * HEIGHT / 2);

    // Pixels sautés entre le vrai haut et drawstart (à cause du clamp)
    img->texpos = 0;
    if (ray->drawstart > true_wall_top)
        img->texpos = (double)(ray->drawstart - true_wall_top) * img->step;

    apply_texture_column(index, get, img, ray);
}

static void	draw_cond(int draw[2], t_cube *get, int index)
{
	if (draw[0] <= draw[1])
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
		get->data.addr[j * line_offset + index] = color_floor;
	return (0);
}
