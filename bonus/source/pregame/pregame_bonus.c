/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pregame_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:17:55 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:16:03 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"
#include "../../includes/cub_moises_bonus.h"

void	prepare_the_game(t_cub *cub)
{
	cub->player = init_player(cub);
	cub->ray = init_ray(cub);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		mlx_error_leave(cub);
	cub->win = mlx_new_window(cub->mlx, SIZE_X, SIZE_Y, "Cub3D");
	if (!cub->win)
	{
		fprintf(stderr, "Error\nFailed to create window\n");
		delete_textures_path(cub);
		delete_map(cub);
		free(cub->player);
		free(cub->ray);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
		free(cub);
		exit(1);
	}
	init_textures(cub);
	cub->img = mlx_new_image(cub->mlx, SIZE_X, SIZE_Y);
	if (!cub->img)
		img_error_leave(cub);
	cub->data = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, \
	&cub->size_line, &cub->endian);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

void	start_the_game(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, &ft_game_loop, cub);
	mlx_hook(cub->win, 2, 1L << 0, &ft_key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, &ft_key_release, cub);
	mlx_hook(cub->win, 17, 0, &ft_exit, cub);
	mlx_loop(cub->mlx);
}
