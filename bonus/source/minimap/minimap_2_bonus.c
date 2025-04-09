/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:00:13 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:41 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minimap_bonus.h"

void	draw_minimap(t_cub *cub)
{
	int	row;
	int	collum;
	int	tile_size;

	tile_size = TILE_SIZE * MINIMAP_SCALE;
	row = 0;
	while (row < cub->map_height)
	{
		collum = 0;
		while (cub->map[row][collum] != '\0')
		{
			draw_tile(cub, row, collum, tile_size);
			collum++;
		}
		row++;
	}
	draw_minimap_rays(cub);
	draw_minimap_player(cub);
}

void	draw_tile(t_cub *cub, int row, int collum, int tile_size)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		color;

	x = collum * tile_size;
	y = row * tile_size;
	if (cub->map[row][collum] == '1')
		color = WALL_COLOR;
	else
		color = VOID_COLOR;
	i = 0;
	while (i < tile_size)
	{
		j = 0;
		while (j < tile_size)
		{
			my_put_pixel(cub, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_rays(t_cub *cub)
{
	int			i;
	t_point		start;
	t_point		end;
	t_minimap	minimap;

	minimap.step = cub->player->fov / (MINIMAP_RAY_COUNT - 1);
	start.x = (int)(cub->player->x * MINIMAP_SCALE);
	start.y = (int)(cub->player->y * MINIMAP_SCALE);
	i = 0;
	while (i < MINIMAP_RAY_COUNT)
	{
		get_minimap_ray(cub, i, &minimap);
		end.x = (int)(minimap.hit_x * MINIMAP_SCALE);
		end.y = (int)(minimap.hit_y * MINIMAP_SCALE);
		draw_line(cub, &start, &end, RAY_COLOR);
		i++;
	}
}

void	get_minimap_ray(t_cub *cub, int i, t_minimap *minimap)
{
	minimap->ray_angle = cub->player->angle - \
		(cub->player->fov / 2) + i * minimap->step;
	minimap->ray_angle = normalize_angle(minimap->ray_angle);
	minimap->h_inter = horizontal_intersection(cub, \
		minimap->ray_angle);
	minimap->v_inter = vertical_intersection(cub, \
		minimap->ray_angle);
	if (minimap->v_inter < minimap->h_inter)
		minimap->distance = minimap->v_inter;
	else
		minimap->distance = minimap->h_inter;
	minimap->hit_x = cub->player->x + \
		minimap->distance * cos(minimap->ray_angle);
	minimap->hit_y = cub->player->y + \
		minimap->distance * sin(minimap->ray_angle);
}

void	draw_minimap_player(t_cub *cub)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = (int)(cub->player->x * MINIMAP_SCALE);
	y = (int)(cub->player->y * MINIMAP_SCALE);
	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			my_put_pixel(cub, x + j, y + i, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}
