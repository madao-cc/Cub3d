/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_leave_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:10:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	mlx_error_leave(t_cub *cub)
{
	fprintf(stderr, "Error\nFailed to initialize mlx\n");
	delete_textures_path(cub);
	delete_map(cub);
	free(cub->player);
	free(cub->ray);
	free(cub);
	exit(1);
}

void	img_error_leave(t_cub *cub)
{
	fprintf(stderr, "Error\nFailed to create image\n");
	delete_textures_path(cub);
	delete_map(cub);
	free(cub->player);
	free(cub->ray);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	free(cub);
	exit(1);
}

void	copy_map_error_leave(t_cub *cub, int i)
{
	fprintf(stderr, "Error\nMemory allocation failed\n");
	while (i-- > 0)
		free(cub->map[i]);
	free(cub->map);
	delete_textures_path(cub);
	free(cub);
	exit(1);
}

void	safe_texture_error_leave(t_cub *cub, int i)
{
	fprintf(stderr, "Error\nFailed to load texture\n");
	free_textures_on_error(cub, i);
	delete_map(cub);
	delete_textures_path(cub);
	free(cub->player);
	free(cub->ray);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	free(cub);
	exit(1);
}
