/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_step_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:47:52 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	move_step(t_cub *cub, double step_x, double step_y, int steps)
{
	double	next_x;
	double	next_y;

	if (steps <= 0)
		return ;
	next_x = cub->player->x + step_x;
	next_y = cub->player->y + step_y;
	check_x_step(cub, next_x, step_x);
	check_y_step(cub, next_y, step_y);
	move_step(cub, step_x, step_y, steps - 1);
}

void	check_x_step(t_cub *cub, double next_x, double step_x)
{
	int		tile_x;
	double	margin;

	margin = 0.1;
	tile_x = next_x / TILE_SIZE;
	if (!is_wall(cub, next_x, cub->player->y))
		cub->player->x = next_x;
	else
	{
		if (step_x > 0)
			cub->player->x = (tile_x * TILE_SIZE) - margin;
		else if (step_x < 0)
			cub->player->x = (tile_x + 1) * TILE_SIZE + margin;
	}
}

void	check_y_step(t_cub *cub, double next_y, double step_y)
{
	int		tile_y;
	double	margin;

	margin = 0.1;
	tile_y = next_y / TILE_SIZE;
	if (!is_wall(cub, cub->player->x, next_y))
		cub->player->y = next_y;
	else
	{
		if (step_y > 0)
			cub->player->y = (tile_y * TILE_SIZE) - margin;
		else if (step_y < 0)
			cub->player->y = (tile_y + 1) * TILE_SIZE + margin;
	}
}

bool	is_wall(t_cub *cub, double x, double y)
{
	int		tile_x;
	int		tile_y;

	tile_x = x / TILE_SIZE;
	tile_y = y / TILE_SIZE;
	if (cub->map[tile_y][tile_x] == '1')
		return (true);
	return (false);
}
