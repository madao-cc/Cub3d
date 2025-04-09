/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:54:35 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

int	copy_to_cub(t_data *cub_data, t_cub *cub)
{
	copy_textures(cub_data, cub);
	copy_colors(cub_data, cub);
	copy_map(cub_data, cub);
	cub->position_x = cub_data->start_pos[POS_X];
	cub->position_y = cub_data->start_pos[POS_Y];
	return (0);
}

void	copy_textures(t_data *cub_data, t_cub *cub)
{
	cub->n_texture.path = ft_strdup(cub_data->textures[NO_TEXTR]);
	cub->s_texture.path = ft_strdup(cub_data->textures[SO_TEXTR]);
	cub->w_texture.path = ft_strdup(cub_data->textures[WE_TEXTR]);
	cub->e_texture.path = ft_strdup(cub_data->textures[EA_TEXTR]);
	if (!cub->n_texture.path || !cub->s_texture.path || \
	!cub->w_texture.path || !cub->e_texture.path)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		delete_textures_path(cub);
		free(cub);
		exit(1);
	}
}

void	copy_colors(t_data *cub_data, t_cub *cub)
{
	cub->floor.red = cub_data->floor[COLOR_R];
	cub->floor.green = cub_data->floor[COLOR_G];
	cub->floor.blue = cub_data->floor[COLOR_B];
	cub->ceiling.red = cub_data->ceil[COLOR_R];
	cub->ceiling.green = cub_data->ceil[COLOR_G];
	cub->ceiling.blue = cub_data->ceil[COLOR_B];
}

void	copy_map(t_data *cub_data, t_cub *cub)
{
	int		i;

	cub->map = calloc(cub_data->map_size[HEIGHT] + 1, sizeof(char *));
	if (!cub->map)
	{
		fprintf(stderr, "Error\nMemory allocation failed\n");
		delete_textures_path(cub);
		free(cub);
		exit(1);
	}
	i = 0;
	while (cub_data->map[i])
	{
		cub->map[i] = ft_strdup(cub_data->map[i]);
		if (!cub->map[i])
			copy_map_error_leave(cub, i);
		i++;
	}
	cub->map[i] = NULL;
	cub->map_width = cub_data->map_size[WIDTH];
	cub->map_height = cub_data->map_size[HEIGHT];
}
