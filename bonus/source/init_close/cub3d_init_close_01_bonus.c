/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_close_01_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:03:09 by antfonse          #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

// FREES STRING AND SETS POINTER TO NULL
char	*free_str(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

// FREES ARRAY OF STRINGS (ONLY ARRAY) AND SETS POINTER TO NULL
char	**free_str_array1d(char **array)
{
	free(array);
	array = NULL;
	return (NULL);
}

// FREES ARRAY OF STRINGS (BOTH ARRAY AND STRINGS) AND SETS POINTERS TO NULL
char	**free_str_array2d(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		array[i] = free_str(array[i]);
		i++;
	}
	free(array);
	array = NULL;
	return (NULL);
}

// INITIALIZE PARSER STRUCT t_data
t_data	*init_parser(void)
{
	t_data	*cub_data;

	cub_data = (t_data *)malloc(sizeof(*cub_data));
	if (!cub_data)
		print_error_exit(MSG_MALLOC, NULL, cub_data);
	cub_data->textures[NO_TEXTR] = NULL;
	cub_data->textures[SO_TEXTR] = NULL;
	cub_data->textures[WE_TEXTR] = NULL;
	cub_data->textures[EA_TEXTR] = NULL;
	cub_data->floor[COLOR_R] = -1;
	cub_data->floor[COLOR_G] = -1;
	cub_data->floor[COLOR_B] = -1;
	cub_data->ceil[COLOR_R] = -1;
	cub_data->ceil[COLOR_G] = -1;
	cub_data->ceil[COLOR_B] = -1;
	cub_data->map = NULL;
	cub_data->line = NULL;
	cub_data->args = NULL;
	cub_data->start_pos[POS_X] = -1;
	cub_data->start_pos[POS_Y] = -1;
	cub_data->map_size[HEIGHT] = 0;
	cub_data->map_size[WIDTH] = 0;
	return (cub_data);
}

// CLEAN PARSER
void	clean_parser(t_data *cub_data)
{
	if (!cub_data)
		return ;
	cub_data->textures[NO_TEXTR] = free_str(cub_data->textures[NO_TEXTR]);
	cub_data->textures[SO_TEXTR] = free_str(cub_data->textures[SO_TEXTR]);
	cub_data->textures[WE_TEXTR] = free_str(cub_data->textures[WE_TEXTR]);
	cub_data->textures[EA_TEXTR] = free_str(cub_data->textures[EA_TEXTR]);
	if (cub_data->map)
		free_str_array2d(cub_data->map);
	if (cub_data->line)
		free(cub_data->line);
	if (cub_data->args)
		free_str_array2d(cub_data->args);
	free(cub_data);
}
