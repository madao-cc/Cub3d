/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:55:33 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/03 12:00:34 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	free_textures_on_error(t_cub *cub, int i)
{
	if (i >= 2)
		mlx_destroy_image(cub->mlx, cub->n_texture.img);
	if (i >= 3)
		mlx_destroy_image(cub->mlx, cub->s_texture.img);
	if (i >= 4)
		mlx_destroy_image(cub->mlx, cub->w_texture.img);
}

void	safe_init_texture(t_texture *texture, void *mlx, t_cub *cub, int i)
{
	texture->img = mlx_xpm_file_to_image(mlx, texture->path, \
	&texture->width, &texture->height);
	if (!texture->img)
		safe_texture_error_leave(cub, i);
	texture->data = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
	&texture->size_line, &texture->endian);
}

void	get_player_angle(t_cub *cub, t_player *player)
{
	if (cub->map[cub->position_y][cub->position_x] == 'N')
		player->angle = 1.5 * M_PI;
	else if (cub->map[cub->position_y][cub->position_x] == 'S')
		player->angle = 0.5 * M_PI;
	else if (cub->map[cub->position_y][cub->position_x] == 'W')
		player->angle = M_PI;
	else if (cub->map[cub->position_y][cub->position_x] == 'E')
		player->angle = 0;
}
