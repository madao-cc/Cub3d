/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:00:28 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	cast_rays(t_cub *cub)
{
	int		ray;
	double	h_intersection;
	double	v_intersection;

	ray = 0;
	cub->ray->ray_angle = cub->player->angle - (cub->player->fov / 2);
	while (ray < SIZE_X)
	{
		cub->ray->wall_hit = 0;
		h_intersection = horizontal_intersection(cub, \
			normalize_angle(cub->ray->ray_angle));
		v_intersection = vertical_intersection(cub, \
			normalize_angle(cub->ray->ray_angle));
		if (v_intersection <= h_intersection)
			cub->ray->distance = v_intersection;
		else
		{
			cub->ray->distance = h_intersection;
			cub->ray->wall_hit = 1;
		}
		render_wall(cub, ray);
		ray++;
		cub->ray->ray_angle += (cub->player->fov / (SIZE_X - 1));
	}
}

double	vertical_intersection(t_cub *cub, float angle)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	v_x = floor(cub->player->x / TILE_SIZE) * TILE_SIZE;
	pixel = check_intersection(angle, &v_x, &x_step, 0);
	v_y = cub->player->y + (v_x - cub->player->x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_step < 0) || \
			(!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, cub))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - cub->player->x, 2) + pow(v_y - cub->player->y, 2)));
}

double	horizontal_intersection(t_cub *cub, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor(cub->player->y / TILE_SIZE) * TILE_SIZE;
	pixel = check_intersection(angle, &h_y, &y_step, 1);
	h_x = cub->player->x + (h_y - cub->player->y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0) || \
			(!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, cub))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - cub->player->x, 2) + pow(h_y - cub->player->y, 2)));
}
