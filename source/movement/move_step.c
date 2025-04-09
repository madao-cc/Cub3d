/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:47:52 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:33:32 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	move_step(t_cub *cub, double step_x, double step_y, int steps)
{
	double	next_x;
	double	next_y;

	if (steps <= 0)
		return ;
	next_x = cub->player->x + step_x;
	next_y = cub->player->y + step_y;
	if (!is_wall(cub, next_x, next_y))
	{
		cub->player->x = next_x;
		cub->player->y = next_y;
		move_step(cub, step_x, step_y, steps - 1);
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
