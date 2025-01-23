/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:12:28 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/01/21 15:35:09 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	int		index;
	
	if (x < 0)
		return ;
	else if (x >= SIZE_X)
		return ;
	if (y < 0)
		return ;
	else if (y >= SIZE_Y)
		return ;
	index = (y * cub->size_line) + (x * (cub->bits_per_pixel / 8));
	cub->data[index] = color & 0xFF;          // Blue component
	cub->data[index + 1] = (color >> 8) & 0xFF;  // Green component
	cub->data[index + 2] = (color >> 16) & 0xFF; // Red component
}

float	normal_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	render_wall(t_cub *cub, int ray)
{
	double	wall_height;
	double	bottom_pixel;
	double	top_pixel;

	cub->ray->distance *= cos(normal_angle(cub->ray->ray_angle - cub->player->angle));
	//wall_height = TILE_SIZE + 100 / cub->ray->distance;
	wall_height = (TILE_SIZE / cub->ray->distance) * ((SIZE_X / 2) / tan(cub->player->fov / 2));
	bottom_pixel = (SIZE_Y / 2) + (wall_height / 2);
	top_pixel = (SIZE_Y / 2) - (wall_height / 2);
	if (bottom_pixel > SIZE_Y)
		bottom_pixel = SIZE_Y;
	if (top_pixel < 0)
		top_pixel = 0;
	// printf("Ray: %d, Distance: %f, Wall Height: %f, Top: %f, Bottom: %f\n", ray, cub->ray->distance, wall_height, top_pixel, bottom_pixel);
	draw_wall(cub, ray, top_pixel, bottom_pixel);
	draw_floor_and_ceiling(cub, ray, bottom_pixel, top_pixel);
}

void	draw_wall(t_cub *cub, int ray, double top_pixel, double bottom_pixel)
{
	int	color;

	color = get_color(cub, cub->ray->wall_hit);
	while (top_pixel < bottom_pixel)
	{
		put_pixel(cub, ray, top_pixel, color);
		top_pixel++;
	}
}

int	get_color(t_cub *cub, int wall_hit)
{
	cub->ray->ray_angle = normal_angle(cub->ray->ray_angle);
	if (wall_hit == 0)
	{
		if (cub->ray->ray_angle > M_PI / 2 && cub->ray->ray_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF);
		else
			return (0xB5B5B5FF);
	}
	else
	{
		if (cub->ray->ray_angle > 0 && cub->ray->ray_angle < M_PI)
			return (0xF5F5F5FF);
		else
			return (0xF5F5F5FF);
	}
}

void	draw_floor_and_ceiling(t_cub *cub, int ray, double bottom_pixel, double top_pixel)
{
	int		i;

	i = bottom_pixel;
	while (i < SIZE_Y)
	{
		put_pixel(cub, ray, i, 0xB99470FF);
		i++;
	}
	i = 0;
	while (i < top_pixel)
	{
		put_pixel(cub, ray, i, 0x89CFF3FF);
		i++;
	}
}
