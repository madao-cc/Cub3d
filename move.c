/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:45:18 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/01/21 20:27:23 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_key_press(int keycode, t_cub *cub)
{
	if(keycode == W)
		cub->player->key_w = true;
	if(keycode == S)
		cub->player->key_s = true;
	if(keycode == A)
		cub->player->key_a = true;
	if(keycode == D)
		cub->player->key_d = true;
	if(keycode == LEFT_ARROW)
		cub->player->left_arrow = true;
	if(keycode == RIGHT_ARROW)
		cub->player->right_arrow = true;
	if (keycode == ESC)
		ft_exit(cub);
	return (0);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	if(keycode == W)
		cub->player->key_w = false;
	if(keycode == S)
		cub->player->key_s = false;
	if(keycode == A)
		cub->player->key_a = false;
	if(keycode == D)
		cub->player->key_d = false;
	if(keycode == LEFT_ARROW)
		cub->player->left_arrow = false;
	if(keycode == RIGHT_ARROW)
		cub->player->right_arrow = false;
	return (0);
}

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

/* void	move_player(t_cub *cub, double move_x, double move_y)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;
	int		tmp_y;
	int		tmp_x;

	new_x = roundf(cub->player->x + move_x);
	new_y = roundf(cub->player->y + move_y);
	map_grid_x = new_x / TILE_SIZE;
	map_grid_y = new_y / TILE_SIZE;
	tmp_y = cub->player->y / TILE_SIZE;
	tmp_x = cub->player->x / TILE_SIZE;
	if (map_grid_y < 0 || map_grid_y >= cub->map_height || map_grid_x < 0 || map_grid_x >= cub->map_width)
		return;
	if (cub->map[map_grid_y][map_grid_x] != '1')
	{
		if (cub->map[map_grid_y][tmp_x] != '1')
		{
			if (cub->map[tmp_y][map_grid_x] != '1')
			{
				cub->player->x = new_x;
				cub->player->y = new_y;
			}
		}
	}
} */

void	move_player(t_cub *cub, double move_x, double move_y)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;
	int		tile_x;
	int		tile_y;
	const double	OFFSET = 1.0;

	new_x = roundf(cub->player->x + move_x);
	new_y = roundf(cub->player->y + move_y);

	tile_x = cub->player->x / TILE_SIZE;
	tile_y = cub->player->y / TILE_SIZE;

	map_grid_x = new_x / TILE_SIZE;
	if (cub->map[tile_y][map_grid_x] != '1')
		cub->player->x = new_x;
	else
	{
		if (move_x > 0)								// Moving right
			cub->player->x = (map_grid_x * TILE_SIZE) - OFFSET;
		else if (move_x < 0)							// Moving left
			cub->player->x = (map_grid_x + 1) * TILE_SIZE + OFFSET;
	}
	map_grid_y = new_y / TILE_SIZE;
	if (cub->map[map_grid_y][tile_x] != '1')
		cub->player->y = new_y;
	else
	{
		if (move_y > 0)								// Moving down
			cub->player->y = (map_grid_y * TILE_SIZE) - OFFSET;
		else if (move_y < 0)							// Moving up
			cub->player->y = (map_grid_y + 1) * TILE_SIZE + OFFSET;
	}
	
}

void	hook_player(t_cub *cub)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (cub->player->right_arrow == true)
		rotate_player(cub, 1);
	// printf("Ok 1\n");
	if (cub->player->left_arrow)
		rotate_player(cub, 0);
	// printf("Ok 2\n");
	if (cub->player->key_w)
	{
		move_x = cos(cub->player->angle) * PLAYER_SPEED;
		move_y = sin(cub->player->angle) * PLAYER_SPEED;
	}
	// printf("Ok 3\n");
	if (cub->player->key_s)
	{
		move_x = -cos(cub->player->angle) * PLAYER_SPEED;
		move_y = -sin(cub->player->angle) * PLAYER_SPEED;
	}
	// printf("Ok 4\n");
	if (cub->player->key_a)
	{
		move_x = sin(cub->player->angle) * PLAYER_SPEED;
		move_y = -cos(cub->player->angle) * PLAYER_SPEED;
	}
	// printf("Ok 5\n");
	if (cub->player->key_d)
	{
		move_x = -sin(cub->player->angle) * PLAYER_SPEED;
		move_y = cos(cub->player->angle) * PLAYER_SPEED;
	}
	// printf("Ok 6\n");
	move_player(cub, move_x, move_y);
	// printf("Ok 7\n");
}