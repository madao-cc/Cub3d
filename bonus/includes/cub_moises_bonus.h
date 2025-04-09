/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_moises_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:18:10 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:18:49 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MOISES_BONUS_H
# define CUB_MOISES_BONUS_H

# include <errno.h> 
# include <stdbool.h>
# include "../../LIBFT/src/libft.h"

// Forward declaration of t_cub
typedef struct s_cub	t_cub;

#include "cub_bonus.h"

// COLORS
# define RESET			"\033[0m"
// RED
# define ERR_COLOR		"\033[1;31m"
// YELLOW
# define ERR_MSG		"\033[1;33m"
// CYAN
# define ERR_INFO		"\033[1;36m"

// TEXTURES INDEX
# define NO_TEXTR		0
# define SO_TEXTR		1
# define WE_TEXTR		2
# define EA_TEXTR		3

// COLORS INDEX
# define COLOR_R		0
# define COLOR_G		1
# define COLOR_B		2

// STARTING POSITION INDEX
# define POS_X			0
# define POS_Y			1

// MAP SIZE INDEX
# define HEIGHT			0
# define WIDTH			1

// FILE EXTENSIONS
# define MAP_EXT		".cub"
# define TEXTR_EXT		".xpm"

// LINE MAX NUMBER OF ARGUMENTS
# define TEXTR_N_ARGS	2
# define RGB_N_ARGS		3

// MAP ARRAY INCREMENTS
# define MAP_ARRAY_INCR	10

// CHARACTER TO REPLACE SPACES IN MAP (0/1)
# define REPLACE_SPACES	'0'

// MAP POSSIBLE CHARACTERS
# define SPACES_WALLS	"01"
# define STARTING_POS	"NSEW"

// MAP BOUNDARY CHECK CHARACTERS
# define BOUNDARY		'1'
# define CHECKED_SPACE	'*'
# define EMPTY			'0'

// ERROR MESSAGES
# define MSG_ERROR		"Error"
# define MSG_MALLOC		"malloc: Cannot allocate memory"
# define MSG_NUM_ARGS	"Wrong number of arguments (expected one)"
# define MSG_MAP_FILE	"Selected file is not a valid .cub file"
# define MSG_LINE_SPLIT	"Can't read arguments in line"
# define MSG_LINE_ARGS	"Wrong number of arguments"
# define MSG_TEXTR_FILE	"Invalid texture file extension (.xpm expected)"
# define MSG_DUP_TEXTR	"Duplicate texture"
# define MSG_DUP_COLOR	"Duplicate color"
# define MSG_CHAR_RGB	"Non numeric values found in RGB arguments"
# define MSG_NO_RGB		"No value found in RGB argument"
# define MSG_MULTI_RGB	"Too many values found in RGB argument"
# define MSG_RANGE_RGB	"RGB values outside range [0,255]"
# define MSG_DATA_LAST	"Found data after map definition"
# define MSG_BAD_CHAR	"Forbidden character found in line"
# define MSG_DUP_CHAR	"A second start position character found in line"
# define MSG_NO_START	"Player's start position not set"
# define MSG_ERR_CLOSED	"Open boundary around starting position"
# define MSG_MISS_NO	"Missing North texture"
# define MSG_MISS_SO	"Missing South texture"
# define MSG_MISS_WE	"Missing West texture"
# define MSG_MISS_EA	"Missing East texture"
# define MSG_MISS_F		"Missing Floor color"
# define MSG_MISS_C		"Missing Ceiling color"
# define MSG_MISS_MAP	"Missing Map"

// CUB3D MAIN DATA STRUCT
typedef struct s_data
{
	char	*textures[4];
	int		floor[3];
	int		ceil[3];
	char	**map;
	char	*line;
	char	**args;
	int		start_pos[2];
	int		map_size[2];
	t_cub	*cub;
}			t_data;

// INITIALIZE / CLOSE / FREE
char	*free_str(char *str);
char	**free_str_array1d(char **array);
char	**free_str_array2d(char **array);
t_data	*init_parser(void);
void	clean_parser(t_data *cub_data);

// PARSE MAP FILE
int		cub_parser(int argc, char *argv[], t_cub *cub);
char	*readline(int map, t_data *cub_data);
void	parse_textures(char *line, t_data *cub_data);
void	parse_colors(char *line, t_data *cub_data);
void	parse_map(int map, char *line, t_data *cub_data);

//CHECK FUNCTIONS
char	**check_split(char *str, char c, int n_args, t_data *cub_data);
char	*check_strdup(char *str, t_data *cub_data);
char	**check_str_array(size_t len, t_data *cub_data);
char	*check_str(size_t len, t_data *cub_data);
int		check_atoi(char *str, t_data *cub_data);
void	check_args(int argc, t_data *cub_data);
int		check_file(char *filename, t_data *cub_data, char *ext, \
		char *error_msg);
void	check_data_after_map(int map, t_data *cub_data);
void	clean_reset_map(char **map);
void	check_valid_map(t_data *cub_data);
void	check_missing_items(t_data *cub_data);

// ERROR HANDLING
void	print_error_exit(char *msg, char *info, t_data *cub_data);
void	print_perror_exit(char *info, t_data *cub_data);

#endif
