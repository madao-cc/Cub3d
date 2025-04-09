/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:17:44 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	complete_texture_wall(t_cub *cub, int ray, t_help helper, int texture_x)
{
	int			texture_y;
	int			y;
	t_texture	*texture;
	double		texture_step;
	double		texture_pos;

	texture = get_texture(cub);
	texture_step = (double)texture->height / helper.wall_height;
	texture_pos = (helper.top_pixel - SIZE_Y / 2 + helper.wall_height / 2) \
	* texture_step;
	y = helper.top_pixel;
	while (y < helper.bottom_pixel)
	{
		texture_y = (int)texture_pos;
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= texture->height)
			texture_y = texture->height - 1;
		texture_pos += texture_step;
		my_put_pixel(cub, ray, y, get_pixel_color(*texture, texture_x, \
		texture_y));
		y++;
	}
}

void	draw_textured_wall(t_cub *cub, int ray, t_help helper)
{
	int			texture_x;
	t_texture	*texture;
	float		wall_offset;

	if (cub->ray->wall_hit == 0)
	{
		texture = get_texture(cub);
		wall_offset = helper.hit_y - floor(helper.hit_y / TILE_SIZE) \
		* TILE_SIZE;
		texture_x = get_texture_x(cub, texture, wall_offset);
	}
	else
	{
		texture = get_texture(cub);
		wall_offset = helper.hit_x - floor(helper.hit_x / TILE_SIZE) \
		* TILE_SIZE;
		texture_x = get_texture_x(cub, texture, wall_offset);
	}
	complete_texture_wall(cub, ray, helper, texture_x);
}

t_texture	*get_texture(t_cub *cub)
{
	if (cub->ray->wall_hit == 0)
	{
		if (cos(cub->ray->ray_angle) > 0)
			return (&cub->w_texture);
		else
			return (&cub->e_texture);
	}
	else
	{
		if (sin(cub->ray->ray_angle) < 0)
			return (&cub->n_texture);
		else
			return (&cub->s_texture);
	}
	return (NULL);
}

int	get_texture_x(t_cub *cub, t_texture *texture, float wall_offset)
{
	int	texture_x;

	if (cub->ray->wall_hit == 0)
	{
		texture_x = (int)(wall_offset * ((float)texture->width / TILE_SIZE));
		if (texture_x < 0)
			texture_x = 0;
		if (texture_x >= texture->width)
			texture_x = texture->width - 1;
		if (cos(cub->ray->ray_angle) < 0)
			texture_x = texture->width - texture_x - 1;
	}
	else
	{
		texture_x = (int)(wall_offset * ((float)texture->width / TILE_SIZE));
		if (texture_x < 0)
			texture_x = 0;
		if (texture_x >= texture->width)
			texture_x = texture->width - 1;
		if (sin(cub->ray->ray_angle) > 0)
			texture_x = texture->width - texture_x - 1;
	}
	return (texture_x);
}

int	get_pixel_color(t_texture texture, int x, int y)
{
	int		index;
	int		color;

	if (x < 0)
		x = 0;
	if (x >= texture.width)
		x = texture.width - 1;
	if (y < 0)
		y = 0;
	if (y >= texture.height)
		y = texture.height - 1;
	index = (y * texture.size_line) + (x * (texture.bits_per_pixel / 8));
	color = *(int *)(texture.data + index);
	return (color);
}
