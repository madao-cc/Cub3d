/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:48:57 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/01/21 15:35:09 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_game_loop(t_cub *cub)
{
	clear_image(cub);
	hook_player(cub);
	cast_rays(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

void	clear_image(t_cub *cub)
{
	int		y;
	int		x;
	
	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			put_pixel(cub, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	cast_rays(t_cub *cub)
{
 	int		ray;
	double	h_intersection;
	double	v_intersection;

	ray = 0;
	cub->ray->ray_angle = cub->player->angle - ( cub->player->fov / 2);
	while (ray < SIZE_X)
	{
		cub->ray->wall_hit = 0;
		h_intersection = horizontal_intersection(cub, normal_angle(cub->ray->ray_angle));
		v_intersection = vertical_intersection(cub, normal_angle(cub->ray->ray_angle));
		if (v_intersection <= h_intersection)
			cub->ray->distance = v_intersection;
		else
		{
			cub->ray->distance = h_intersection;
			cub->ray->wall_hit = 1;
		}
		// printf("From cast_rays: Ray: %d, Angle: %f, H: %f, V: %f\n", ray, cub->ray->ray_angle, h_intersection, v_intersection);
		render_wall(cub, ray);
		ray++;
		cub->ray->ray_angle += (cub->player->fov / (SIZE_X - 1));
		// printf("Ray Angle Increment: %f\n", (cub->player->fov / SIZE_X));
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
	if ((unit_circle(angle, 'x') && y_step < 0) || (!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, cub))
	{
		v_x += x_step;
		v_y += y_step;
		// printf("V-Step: VX: %f, VY: %f\n", v_x, v_y);
	}
	// printf("From vert_intersec: V: Initial VX: %f, VY: %f, X-Step: %f, Y-Step: %f\n", v_x, v_y, x_step, y_step);
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
	if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, cub))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - cub->player->x, 2) + pow(h_y - cub->player->y, 2)));
}

int	wall_hit(float x, float y, t_cub *cub)
{
	int		map_x;
	int		map_y;

	if (x < 0 || y < 0)
		return (0);
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_x >= cub->map_width || map_y >= cub->map_height)
		return (0);
	if (cub->map[map_y] && map_x <= (int)strlen(cub->map[map_y]))
	{
		if (cub->map[map_y][map_x] == '1')
			return (0);
	}
	return (1);
}

int	check_intersection(float angle, float *intersection, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*intersection += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*intersection += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}
