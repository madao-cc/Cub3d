/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   furnace_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:29:06 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	delete_map(t_cub *cub)
{
	int		i;

	i = 0;
	while (cub->map[i])
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
}

void	delete_textures_path(t_cub *cub)
{
	free(cub->n_texture.path);
	free(cub->s_texture.path);
	free(cub->w_texture.path);
	free(cub->e_texture.path);
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
	free(cub->n_texture.path);
	free(cub->s_texture.path);
	free(cub->w_texture.path);
	free(cub->e_texture.path);
	destroy_textures(cub);
	mlx_destroy_image(cub->mlx, cub->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	free(cub);
	ft_printf("\033[0;31mYou decided to leave \
	the game, goodbye\033[0m\n");
	exit(0);
	return (0);
}

void	destroy_textures(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->n_texture.img);
	mlx_destroy_image(cub->mlx, cub->s_texture.img);
	mlx_destroy_image(cub->mlx, cub->w_texture.img);
	mlx_destroy_image(cub->mlx, cub->e_texture.img);
}
