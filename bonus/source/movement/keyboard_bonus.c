/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:35:52 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->player->key_w = true;
	if (keycode == S)
		cub->player->key_s = true;
	if (keycode == A)
		cub->player->key_a = true;
	if (keycode == D)
		cub->player->key_d = true;
	if (keycode == LEFT_ARROW)
		cub->player->left_arrow = true;
	if (keycode == RIGHT_ARROW)
		cub->player->right_arrow = true;
	if (keycode == ESC)
		ft_exit(cub);
	return (0);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->player->key_w = false;
	if (keycode == S)
		cub->player->key_s = false;
	if (keycode == A)
		cub->player->key_a = false;
	if (keycode == D)
		cub->player->key_d = false;
	if (keycode == LEFT_ARROW)
		cub->player->left_arrow = false;
	if (keycode == RIGHT_ARROW)
		cub->player->right_arrow = false;
	return (0);
}
