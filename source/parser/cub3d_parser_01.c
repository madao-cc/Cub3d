/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antfonse <antfonse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:20:44 by antfonse          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:07 by antfonse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// PARSE TEXTURES
void	parse_textures(char *line, t_data *cub_data)
{
	char	**args;
	int		i;
	int		fd;

	args = check_split(line, ' ', TEXTR_N_ARGS, cub_data);
	if (!ft_strncmp(args[0], "NO", 2))
		i = NO_TEXTR;
	else if (!ft_strncmp(args[0], "SO", 2))
		i = SO_TEXTR;
	else if (!ft_strncmp(args[0], "WE", 2))
		i = WE_TEXTR;
	else if (!ft_strncmp(args[0], "EA", 2))
		i = EA_TEXTR;
	if (cub_data->textures[i] != NULL)
		print_error_exit(MSG_DUP_TEXTR, line, cub_data);
	fd = check_file(args[1], cub_data, TEXTR_EXT, MSG_TEXTR_FILE);
	close (fd);
	cub_data->textures[i] = check_strdup(args[1], cub_data);
}

// PARSE COLORS (FLOOR + CEILING)
void	parse_colors(char *line, t_data *cub_data)
{
	char	**args;
	char	*line2;
	int		*color;

	line2 = line;
	while (line2 && (*line2 == 'F' || *line2 == 'C' || *line2 == ' '))
		line2++;
	args = check_split(line2, ',', RGB_N_ARGS, cub_data);
	if (!ft_strncmp(line, "F ", 2))
		color = cub_data->floor;
	else if (!ft_strncmp(line, "C ", 2))
		color = cub_data->ceil;
	if (color[0] != -1)
		print_error_exit(MSG_DUP_COLOR, line, cub_data);
	color[COLOR_R] = check_atoi(args[COLOR_R], cub_data);
	color[COLOR_G] = check_atoi(args[COLOR_G], cub_data);
	color[COLOR_B] = check_atoi(args[COLOR_B], cub_data);
}

// INCREASE THE SIZE OF THE MAP ARRAY TO A GIVEN SIZE (COPY CONTENTS)
static char	**update_str_array(size_t map_size, t_data *cub_data)
{
	char	**str_array;
	size_t	i;

	str_array = check_str_array(map_size, cub_data);
	if (cub_data->map)
	{
		i = 0;
		while (cub_data->map[i])
		{
			str_array[i] = cub_data->map[i];
			i++;
		}
		str_array[i] = NULL;
		cub_data->map = free_str_array1d(cub_data->map);
		cub_data->map = str_array;
	}
	else
		cub_data->map = str_array;
	return (str_array);
}

// READ MAP
static void	read_map(int map, char *line, t_data *cub_data)
{
	char	**str_array;
	size_t	i;
	size_t	map_size;

	map_size = MAP_ARRAY_INCR + 1;
	str_array = update_str_array(map_size, cub_data);
	i = 0;
	while (line && *line != '\0')
	{
		if (i == map_size - 1)
		{
			str_array[i] = NULL;
			map_size = map_size + MAP_ARRAY_INCR;
			str_array = update_str_array(map_size, cub_data);
		}
		str_array[i] = check_strdup(line, cub_data);
		i++;
		line = readline(map, cub_data);
	}
	str_array[i] = NULL;
}

// PARSE MAP
void	parse_map(int map, char *line, t_data *cub_data)
{
	read_map(map, line, cub_data);
	check_data_after_map(map, cub_data);
	check_valid_map(cub_data);
}
