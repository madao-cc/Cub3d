/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:18:10 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:26:29 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# include "cub_moises.h"

// USER SPECIFICATIONS
# define DEBUG_MODE 1			// Debug mode

// SPECIFIC DEFINITIONS FOR THE GAME
# define SIZE_X 1900			// Screen width
# define SIZE_Y 1000			// Screen height
# define TILE_SIZE 30			// Size of the tiles
# define FOV 60				// Field of view
# define PLAYER_SPEED 4			// Speed of the player
# define ROTATION_SPEED 0.045		// Speed of the rotation
# define M_PI 3.14159265358979323846	// Pi

// MOVEMENT DEFINITIONS
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307

typedef struct s_help
{
	double	top_pixel;
	double	bottom_pixel;
	double	wall_height;
	double	hit_x;
	double	hit_y;
}	t_help;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_texture
{
	char	*path;
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_ray
{
	float	ray_angle;
	float	distance;
	int		wall_hit;
}	t_ray;

typedef struct s_player
{
	float	x;		// X position of the player in pixels
	float	y;		// Y position of the player in pixels
	float	angle;		// Angle of the player
	float	fov;		// Field of view
	bool	key_w;		// Key W pressed
	bool	key_s;		// Key S pressed
	bool	key_a;		// Key A pressed
	bool	key_d;		// Key D pressed
	bool	left_arrow;	// Key left pressed
	bool	right_arrow;	// Key right pressed
}	t_player;

typedef struct s_cub
{
	void		*mlx;		// Mlx pointer
	void		*win;		// Window pointer
	void		*img;		// Image pointer
	int			position_x;	// Player X position in the map
	int			position_y;	// Player Y position in the map
	int			map_width;	// Map width
	int			map_height;	// Map height
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_player	*player;
	char		**map;
	t_ray		*ray;
	t_texture	n_texture;
	t_texture	s_texture;
	t_texture	w_texture;
	t_texture	e_texture;
	t_color		floor;
	t_color		ceiling;
}	t_cub;

/*****************************************************
******************************************************
*********************PREGAME**************************
******************************************************
*****************************************************/

// PREGAME.C
void		prepare_the_game(t_cub *cub);
void		start_the_game(t_cub *cub);

// COPY.C
int			copy_to_cub(t_data *cub_data, t_cub *cub);
void		copy_textures(t_data *cub_data, t_cub *cub);
void		copy_colors(t_data *cub_data, t_cub *cub);
void		copy_map(t_data *cub_data, t_cub *cub);

// INIT.C
t_cub		*init_cub(void);
void		init_textures(t_cub *cub);
t_player	*init_player(t_cub *cub);
t_ray		*init_ray(t_cub *cub);

// INIT_HELPERS.C
void		free_textures_on_error(t_cub *cub, int i);
void		safe_init_texture(t_texture *texture, void *mlx, t_cub *cub, int i);
void		get_player_angle(t_cub *cub, t_player *player);

/*****************************************************
******************************************************
*********************GAME*****************************
******************************************************
*****************************************************/

// RAY.C
void		cast_rays(t_cub *cub);
double		vertical_intersection(t_cub *cub, float angle);
double		horizontal_intersection(t_cub *cub, float angle);

// RAY_HELPERS.C
int			wall_hit(float x, float y, t_cub *cub);
int			check_intersection(float angle, float *intersect, \
	float *step, int not_wall);
int			unit_circle(float angle, char c);

// GAME_LOOP.C
int			ft_game_loop(t_cub *cub);
void		clear_image(t_cub *cube);

/*****************************************************
******************************************************
*********************RENDER***************************
******************************************************
*****************************************************/

// RENDER.C
void		render_wall(t_cub *cub, int ray);
void		draw_floor_and_ceiling(t_cub *cub, int ray, \
	double bottom_pixel, double top_pixel);

// RENDER_HELPERS.C
void		my_put_pixel(t_cub *cub, int x, int y, int color);
float		normalize_angle(float angle);

// TEXTURING.C
void		draw_textured_wall(t_cub *cub, int ray, t_help helper);
int			get_pixel_color(t_texture texture, int x, int y);

t_texture	*get_texture(t_cub *cub);
int			get_texture_x(t_cub *cub, t_texture *texture, float wall_offset);
void		complete_texture_wall(t_cub *cub, \
	int ray, t_help helper, int texture_x);

/*****************************************************
******************************************************
*********************MOVEMENT*************************
******************************************************
*****************************************************/

// KEYBOARD.C
int			ft_key_press(int keycode, t_cub *cub);
int			ft_key_release(int keycode, t_cub *cub);

// MOVE_PLAYER.C
void		rotate_player(t_cub *cub, int i);
void		move_player(t_cub *cub, double move_x, double move_y);

// MOVE_STEP.C
void		move_step(t_cub *cub, double step_x, double step_y, int steps);
void		check_x_step(t_cub *cub, double next_x, double step_x);
void		check_y_step(t_cub *cub, double next_y, double step_y);
bool		is_wall(t_cub *cub, double x, double y);

// CHECK_MOVEMENT.C
void		check_player_movement(t_cub *cub);
void		check_rotate(t_cub *cub);
double		get_move_x(t_cub *cub);
double		get_move_y(t_cub *cub);

/*****************************************************
******************************************************
*****************ERROR_HANDLING***********************
******************************************************
*****************************************************/

// FURNACE.C
void		delete_map(t_cub *cub);
void		delete_textures_path(t_cub *cub);
int			ft_exit(t_cub *cub);
void		destroy_textures(t_cub *cub);

// CLEAN_AND_LEAVE.C
void		mlx_error_leave(t_cub *cub);
void		img_error_leave(t_cub *cub);
void		copy_map_error_leave(t_cub *cub, int i);
void		safe_texture_error_leave(t_cub *cub, int i);

#endif
