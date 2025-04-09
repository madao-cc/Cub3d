/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:37:52 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/03 12:05:28 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	check_player_movement(t_cub *cub)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	check_rotate(cub);
	move_x = get_move_x(cub);
	move_y = get_move_y(cub);
	move_player(cub, move_x, move_y);
}

void	check_rotate(t_cub *cub)
{
	if (cub->player->right_arrow == true)
		rotate_player(cub, 1);
	if (cub->player->left_arrow == true)
		rotate_player(cub, 0);
}

double	get_move_x(t_cub *cub)
{
	if (cub->player->key_w)
		return (cos(cub->player->angle) * PLAYER_SPEED);
	if (cub->player->key_s)
		return (-cos(cub->player->angle) * PLAYER_SPEED);
	if (cub->player->key_a)
		return (sin(cub->player->angle) * PLAYER_SPEED);
	if (cub->player->key_d)
		return (-sin(cub->player->angle) * PLAYER_SPEED);
	return (0);
}

double	get_move_y(t_cub *cub)
{
	if (cub->player->key_w)
		return (sin(cub->player->angle) * PLAYER_SPEED);
	if (cub->player->key_s)
		return (-sin(cub->player->angle) * PLAYER_SPEED);
	if (cub->player->key_a)
		return (-cos(cub->player->angle) * PLAYER_SPEED);
	if (cub->player->key_d)
		return (cos(cub->player->angle) * PLAYER_SPEED);
	return (0);
}
