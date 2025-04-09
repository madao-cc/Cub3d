/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_02_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:20:44 by antfonse          #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

static void	rgb_val_error(char *str, t_data *cub_data)
{
	bool	word;
	int		nbr;
	int		i;

	word = false;
	nbr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 9 || (str[i] > 13 && str[i] < 48 && str[i] != 32) \
		|| str[i] > 57)
			print_error_exit(MSG_CHAR_RGB, cub_data->line, cub_data);
		if (str[i] != ' ' && !word)
		{
			word = true;
			nbr++;
		}
		if (str[i] == ' ' && word)
			word = false;
		i++;
	}
	if (nbr == 0)
		print_error_exit(MSG_NO_RGB, cub_data->line, cub_data);
	if (nbr > 1)
		print_error_exit(MSG_MULTI_RGB, cub_data->line, cub_data);
}

// CONVERT STRING TO INTEGER AND CHECK FOR ERRORS
int	check_atoi(char *str, t_data *cub_data)
{
	int		nb;

	rgb_val_error(str, cub_data);
	nb = ft_atoi(str);
	if (nb < 0 || nb > 255)
		print_error_exit(MSG_RANGE_RGB, cub_data->line, cub_data);
	return (nb);
}
