/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:17:55 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/01/23 11:33:56 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(void)
{
	t_cub	*cub;

	cub = init_cub();
	prepare_the_game(cub);
	start_the_game(cub);
	return (0);
}

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = calloc(1, sizeof(t_cub));
	if (!cub)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		exit(1);
	}
	cub->position_x = 14;
	cub->position_y = 3;
	cub->map_width = 25;
	cub->map_height = 9;
	return (cub);
}

void	prepare_the_game(t_cub *cub)
{
	cub->map = get_map();
	cub->player = init_player(cub);
	cub->ray = init_ray();
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, SIZE_X, SIZE_Y, "Cub3D");
	cub->img = mlx_new_image(cub->mlx, SIZE_X, SIZE_Y);
	cub->data = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->size_line, &cub->endian);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	
}

char	**get_map(void)
{
	char	**map;
	
	map = calloc(10, sizeof(char *));
	if (!map)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		exit(1);
	}
	map[0] = strdup("1111111111111111111111111");
	map[1] = strdup("1000000000101010100100001");
	map[2] = strdup("1001000000000P00000000001");
	map[3] = strdup("1001000000000000001000001");
	map[4] = strdup("1001000000000000001000001");
	map[5] = strdup("1001000000100000001000001");
	map[6] = strdup("1001000000000000001000001");
	map[7] = strdup("1001000000001000001000001");
	map[8] = strdup("1111111111111111111111111");
	map[9] = NULL;
	return (map);
}

t_player	*init_player(t_cub *cub)
{
	t_player	*player;

	player = calloc(1, sizeof(t_player));
	if (!player)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		exit(1);
	}
	player->x = cub->position_x * TILE_SIZE + TILE_SIZE / 2;
	player->y = cub->position_y * TILE_SIZE + TILE_SIZE / 2;
	player->angle = M_PI;
	player->fov = (FOV * M_PI / 180);
	player->key_w = false;
	player->key_s = false;
	player->key_a = false;
	player->key_d = false;
	player->left_arrow = false;
	player->right_arrow = false;
	return (player);
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = calloc(1, sizeof(t_ray));
	if (!ray)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		exit(1);
	}
	return (ray);
}

int	ft_exit(t_cub *cub)
{
	int		i;

	i = 0;
	while (cub->map[i])
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
	free(cub->player);
	free(cub->ray);
	mlx_destroy_image(cub->mlx, cub->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub);
	fprintf(stderr, "\033[0;31mYou decided to leave the game, goodbye\033[0m\n");
	exit(0);
	return (0);
}

void	start_the_game(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, &ft_game_loop, cub);
	mlx_hook(cub->win, 2, 1L<<0, &ft_key_press, cub);
	mlx_hook(cub->win, 3, 1L<<1, &ft_key_release, cub);
	mlx_hook(cub->win, 17, 0, &ft_exit, cub);
	mlx_loop(cub->mlx);
}
