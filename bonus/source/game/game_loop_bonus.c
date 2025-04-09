/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:48:57 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

int	ft_game_loop(t_cub *cub)
{
	clear_image(cub);
	check_player_movement(cub);
	cast_rays(cub);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

void	clear_image(t_cub *cub)
{
	int		y;
	int		x;

	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			my_put_pixel(cub, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
