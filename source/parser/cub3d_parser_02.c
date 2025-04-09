/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:20:44 by antfonse          #+#    #+#             */
/*   Updated: 2025/03/02 11:46:49 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// READ A LINE FROM A FILE AND TRIMS SPACES AND '\n' FROM BEGINNING AND END
char	*readline(int map, t_data *cub_data)
{
	char	*line;

	line = get_next_line(map);
	if (!line)
		return (line);
	cub_data->line = free_str(cub_data->line);
	cub_data->line = ft_strtrim(line, "\t\n\v\f\r");
	free(line);
	return (cub_data->line);
}

static char	*skip_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

// MAP FILE PARSER
static void	file_parser(int map, t_data *cub_data)
{
	char	*line;
	char	*line2;

	while (1)
	{
		line = readline(map, cub_data);
		if (!line)
			break ;
		line2 = skip_space(line);
		if (*line2 == '\0' || *line2 == '\n')
			continue ;
		if (!ft_strncmp(line2, "NO ", 3) || !ft_strncmp(line2, "SO ", 3) \
			|| !ft_strncmp(line2, "WE ", 3) || !ft_strncmp(line2, "EA ", 3))
			parse_textures(line2, cub_data);
		else if (!ft_strncmp(line2, "F ", 2) || !ft_strncmp(line2, "C ", 2))
			parse_colors(line2, cub_data);
		else
		{
			parse_map(map, line, cub_data);
			break ;
		}
	}
}

// IMPRIMIR MAPA
static void	print_data(t_data *cub_data)
{
	int	j;
	int	i;

	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\n", cub_data->textures[NO_TEXTR], \
	cub_data->textures[SO_TEXTR], cub_data->textures[WE_TEXTR], \
	cub_data->textures[EA_TEXTR]);
	printf("FLOOR: [%d, %d, %d]\n", cub_data->floor[COLOR_R], \
	cub_data->floor[COLOR_G], cub_data->floor[COLOR_B]);
	printf("CEILING: [%d, %d, %d]\n", cub_data->ceil[COLOR_R], \
	cub_data->ceil[COLOR_G], cub_data->ceil[COLOR_B]);
	j = 0;
	while (cub_data->map[j])
	{
		i = 0;
		while (cub_data->map[j][i])
		{
			printf("%c", cub_data->map[j][i]);
			if (cub_data->map[j][i + 1] != '\0')
				printf(" ");
			i++;
		}
		printf("\n");
		j++;
	}
	printf("MAP SIZE (HEIGHT X WIDTH): %d x %d\n", cub_data->map_size[HEIGHT], \
	cub_data->map_size[WIDTH]);
	printf("SPAWN POSITION: X = %d Y = %d\n", cub_data->start_pos[POS_X], \
	cub_data->start_pos[POS_Y]);
}

// MAIN PARSER FUNCTION
int	cub_parser(int argc, char *argv[], t_cub *cub)
{
	t_data	*cub_data;
	int		map;

	cub_data = init_parser();
	cub_data->cub = cub;
	check_args(argc, cub_data);
	map = check_file(argv[1], cub_data, MAP_EXT, MSG_MAP_FILE);
	file_parser(map, cub_data);
	close(map);
	check_missing_items(cub_data);
	copy_to_cub(cub_data, cub);
	//?DELETE
	print_data(cub_data);
	clean_parser(cub_data);
	return (EXIT_SUCCESS);
}
