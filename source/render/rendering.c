/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:28 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/14 09:42:25 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_floor_and_ceiling(t_cub *cub, int ray, double bottom_pixel, \
	double top_pixel)
{
	int		i;
	int		floor_color;
	int		ceiling_color;

	floor_color = (cub->floor.red << 16) + \
		(cub->floor.green << 8) + cub->floor.blue;
	ceiling_color = (cub->ceiling.red << 16) + \
		(cub->ceiling.green << 8) + cub->ceiling.blue;
	i = bottom_pixel;
	while (i < SIZE_Y)
	{
		my_put_pixel(cub, ray, i, floor_color);
		i++;
	}
	i = 0;
	while (i < top_pixel)
	{
		my_put_pixel(cub, ray, i, ceiling_color);
		i++;
	}
}

void	render_wall(t_cub *cub, int ray)
{
	t_help	helper;
	double	fish_eye_distance;

	fish_eye_distance = cub->ray->distance;
	cub->ray->distance = cub->ray->distance \
	* cos(normalize_angle(cub->ray->ray_angle - cub->player->angle));
	helper.wall_height = (TILE_SIZE / cub->ray->distance) \
	* ((SIZE_X / 2) / tan(cub->player->fov / 2));
	helper.bottom_pixel = (SIZE_Y / 2) + (helper.wall_height / 2);
	helper.top_pixel = (SIZE_Y / 2) - (helper.wall_height / 2);
	if (helper.bottom_pixel > SIZE_Y)
		helper.bottom_pixel = SIZE_Y;
	if (helper.top_pixel < 0)
		helper.top_pixel = 0;
	helper.hit_x = cub->player->x + fish_eye_distance * \
		cos(cub->ray->ray_angle);
	helper.hit_y = cub->player->y + fish_eye_distance * \
		sin(cub->ray->ray_angle);
	draw_textured_wall(cub, ray, helper);
	draw_floor_and_ceiling(cub, ray, helper.bottom_pixel, helper.top_pixel);
}
