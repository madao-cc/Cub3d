/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helpers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:29:31 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	my_put_pixel(t_cub *cub, int x, int y, int color)
{
	int	index;

	if (x < 0)
		return ;
	else if (x >= SIZE_X)
		return ;
	if (y < 0)
		return ;
	else if (y >= SIZE_Y)
		return ;
	index = (y * cub->size_line) + (x * (cub->bits_per_pixel / 8));
	cub->data[index] = color & 0xFF;
	cub->data[index + 1] = (color >> 8) & 0xFF;
	cub->data[index + 2] = (color >> 16) & 0xFF;
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
