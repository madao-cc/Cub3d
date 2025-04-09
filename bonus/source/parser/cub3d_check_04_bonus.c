/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_04_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:53:23 by antfonse          #+#    #+#             */
/*   Updated: 2025/03/15 20:15:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

// REPLACE SPACES IN MAP BY CHOSEN CHARACTER (0/1)
// GET MAP SIZE (HEIGHT X WIDTH)
static void	replace_spaces(char **map, t_data *cub_data)
{
	int	i;
	int	j;
	int	width;

	if (!map)
		return ;
	i = 0;
	width = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 32)
				map[i][j] = REPLACE_SPACES;
			j++;
		}
		if (j > width)
			width = j;
		i++;
	}
	cub_data->map_size[HEIGHT] = i;
	cub_data->map_size[WIDTH] = width;
}

// CHECK ALL THE CHARACTERS PRESENT IN MAP ARE VALID - 0/1 + 1x N/S/E/W
// GET STARTING POSITION
static void	check_map_char(char **map, t_data *cub_data)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(SPACES_WALLS, map[i][j]))
			{
				if (!ft_strchr(STARTING_POS, map[i][j]))
					print_error_exit(MSG_BAD_CHAR, map[i], cub_data);
				else if (cub_data->start_pos[POS_X] != -1)
					print_error_exit(MSG_DUP_CHAR, map[i], cub_data);
				cub_data->start_pos[POS_X] = j;
				cub_data->start_pos[POS_Y] = i;
			}
			j++;
		}
		i++;
	}
	if (cub_data->start_pos[POS_X] == -1 && cub_data->start_pos[POS_Y] == -1)
		print_error_exit(MSG_NO_START, NULL, cub_data);
}

// NORMALIZE MAP (MAKE ALL LINES HAVE THE SAME NUMBER OF COLUMNS - RECTANGLE)
static void	normalize_map(char **map, t_data *cub_data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		line = check_str(cub_data->map_size[WIDTH] + 1, cub_data);
		j = 0;
		while (map[i][j])
		{
			line[j] = map[i][j];
			j++;
		}
		while (j < cub_data->map_size[WIDTH])
		{
			line[j] = '0';
			j++;
		}
		line[j] = '\0';
		free_str(cub_data->map[i]);
		cub_data->map[i] = line;
		i++;
	}
}

// SEED FILL AREA AROUND STARTING POSITION TO LOOK FOR A CLOSED BOUNDARY
static void	seed_fill(char **map, int x, int y, t_data *cub_data)
{
	if (map[y][x] == BOUNDARY || map[y][x] == CHECKED_SPACE)
		return ;
	if (x == 0 || x == cub_data->map_size[WIDTH] - 1 || y == 0 || \
		y == cub_data->map_size[HEIGHT] - 1)
		print_error_exit(MSG_ERR_CLOSED, NULL, cub_data);
	map[y][x] = '*';
	seed_fill(map, x + 1, y, cub_data);
	seed_fill(map, x - 1, y, cub_data);
	seed_fill(map, x, y + 1, cub_data);
	seed_fill(map, x, y - 1, cub_data);
}

// CHECK MAP IS VALID
void	check_valid_map(t_data *cub_data)
{
	char	orientation;
	int		x;
	int		y;

	if (!cub_data->map)
		return ;
	replace_spaces(cub_data->map, cub_data);
	check_map_char(cub_data->map, cub_data);
	normalize_map(cub_data->map, cub_data);
	x = cub_data->start_pos[POS_X];
	y = cub_data->start_pos[POS_Y];
	orientation = cub_data->map[y][x];
	seed_fill(cub_data->map, x, y, cub_data);
	clean_reset_map(cub_data->map);
	cub_data->map[y][x] = orientation;
}
