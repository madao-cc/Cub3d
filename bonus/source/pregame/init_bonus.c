/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:52:10 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = calloc(1, sizeof(t_cub));
	if (!cub)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		exit(1);
	}
	return (cub);
}

void	init_textures(t_cub *cub)
{
	safe_init_texture(&cub->n_texture, cub->mlx, cub, 1);
	safe_init_texture(&cub->s_texture, cub->mlx, cub, 2);
	safe_init_texture(&cub->w_texture, cub->mlx, cub, 3);
	safe_init_texture(&cub->e_texture, cub->mlx, cub, 4);
}

t_player	*init_player(t_cub *cub)
{
	t_player	*player;

	player = calloc(1, sizeof(t_player));
	if (!player)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		delete_textures_path(cub);
		delete_map(cub);
		free(cub);
		exit(1);
	}
	player->x = cub->position_x * TILE_SIZE + TILE_SIZE / 2;
	player->y = cub->position_y * TILE_SIZE + TILE_SIZE / 2;
	get_player_angle(cub, player);
	player->fov = (FOV * M_PI / 180);
	player->key_w = false;
	player->key_s = false;
	player->key_a = false;
	player->key_d = false;
	player->left_arrow = false;
	player->right_arrow = false;
	return (player);
}

t_ray	*init_ray(t_cub *cub)
{
	t_ray	*ray;

	ray = calloc(1, sizeof(t_ray));
	if (!ray)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		delete_map(cub);
		delete_textures_path(cub);
		free(cub->player);
		free(cub);
		exit(1);
	}
	return (ray);
}
