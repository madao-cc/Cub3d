/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:45:18 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	rotate_player(t_cub *cub, int i)
{
	if (i == 1)
	{
		cub->player->angle += ROTATION_SPEED;
		if (cub->player->angle > 2 * M_PI)
			cub->player->angle -= 2 * M_PI;
	}
	else
	{
		cub->player->angle -= ROTATION_SPEED;
		if (cub->player->angle < 0)
			cub->player->angle += 2 * M_PI;
	}
}

void	move_player(t_cub *cub, double move_x, double move_y)
{
	double	steps;
	double	step_x;
	double	step_y;

	steps = 10;
	step_x = move_x / steps;
	step_y = move_y / steps;
	move_step(cub, step_x, step_y, steps);
}
