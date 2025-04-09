/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_03_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:46:36 by antfonse          #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

// CHECK NUMBER OF INPUT ARGUMENTS
void	check_args(int argc, t_data *cub_data)
{
	if (argc != 2)
		print_error_exit(MSG_NUM_ARGS, NULL, cub_data);
}

// CHECK FILE EXISTS AND OPENS IT
int	check_file(char *filename, t_data *cub_data, char *ext, char *error_msg)
{
	int	fd;

	if (ft_strncmp(filename + ft_strlen(filename) - 4, ext, 4) != 0)
		print_error_exit(error_msg, filename, cub_data);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_perror_exit(filename, cub_data);
	return (fd);
}

// CHECK IF THERES IS DATA AFTER MAP DEFINITION
void	check_data_after_map(int map, t_data *cub_data)
{
	char	*line;

	while (1)
	{
		line = readline(map, cub_data);
		if (!line)
			break ;
		else if (*line == '\0')
			continue ;
		else
			print_error_exit(MSG_DATA_LAST, line, cub_data);
	}
}

// CLEAN MAP FROM SEED FILL SPECIAL CHARACTER
void	clean_reset_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == CHECKED_SPACE)
				map[i][j] = EMPTY;
			j++;
		}
		i++;
	}
}

// CHECK ALL REQUIRED ITEMS ARE PRESENT IN MAP FILE
void	check_missing_items(t_data *cub_data)
{
	if (cub_data->textures[NO_TEXTR] == NULL)
		print_error_exit(MSG_MISS_NO, NULL, cub_data);
	if (cub_data->textures[SO_TEXTR] == NULL)
		print_error_exit(MSG_MISS_SO, NULL, cub_data);
	if (cub_data->textures[WE_TEXTR] == NULL)
		print_error_exit(MSG_MISS_WE, NULL, cub_data);
	if (cub_data->textures[EA_TEXTR] == NULL)
		print_error_exit(MSG_MISS_EA, NULL, cub_data);
	if (cub_data->floor[COLOR_R] == -1 || cub_data->floor[COLOR_G] == -1 \
		|| cub_data->floor[COLOR_B] == -1)
		print_error_exit(MSG_MISS_F, NULL, cub_data);
	if (cub_data->ceil[COLOR_R] == -1 || cub_data->ceil[COLOR_G] == -1 \
		|| cub_data->ceil[COLOR_B] == -1)
		print_error_exit(MSG_MISS_C, NULL, cub_data);
	if (cub_data->map == NULL)
		print_error_exit(MSG_MISS_MAP, NULL, cub_data);
}
