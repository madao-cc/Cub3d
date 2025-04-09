/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:59:38 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:41 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minimap_bonus.h"

static int	is_wall_at(t_cub *cub, t_point current)
{
	int	tile_x;
	int	tile_y;

	tile_x = current.x / (TILE_SIZE * MINIMAP_SCALE);
	tile_y = current.y / (TILE_SIZE * MINIMAP_SCALE);
	if (tile_y >= 0 && tile_y < cub->map_height && \
		tile_x >= 0 && tile_x < cub->map_width)
	{
		if (cub->map[tile_y][tile_x] == '1')
			return (1);
	}
	return (0);
}

void	draw_line(t_cub *cub, t_point *start, t_point *end, int color)
{
	t_point	delta;
	t_point	step;
	t_point	current;
	int		error;
	int		max_iterations;

	delta = calculate_delta(start, end);
	step = calculate_step(start, end);
	error = delta.x - delta.y;
	current.x = start->x;
	current.y = start->y;
	max_iterations = delta.x + delta.y;
	while (max_iterations-- > 0)
	{
		my_put_pixel(cub, current.x, current.y, color);
		if (is_wall_at(cub, current))
			break ;
		if (current.x == end->x && current.y == end->y)
			break ;
		check_error(&error, delta, step, &current);
	}
}

void	check_error(int *error, t_point delta, t_point step, t_point *current)
{
	if (*error * 2 > -delta.y)
	{
		*error -= delta.y;
		current->x += step.x;
	}
	if (*error * 2 < delta.x)
	{
		*error += delta.x;
		current->y += step.y;
	}
}

t_point	calculate_delta(t_point *start, t_point *end)
{
	t_point	delta;

	delta.x = abs(end->x - start->x);
	delta.y = abs(end->y - start->y);
	return (delta);
}

t_point	calculate_step(t_point *start, t_point *end)
{
	t_point	step;

	if (start->x < end->x)
		step.x = 1;
	else
		step.x = -1;
	if (start->y < end->y)
		step.y = 1;
	else
		step.y = -1;
	return (step);
}
