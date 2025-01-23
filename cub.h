/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:18:10 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/01/23 11:52:34 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <mlx.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"

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
	float 	angle;		// Angle of the player

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

	int		position_x;	// Player X position in the map
	int		position_y;	// Player Y position in the map
	int		map_width;	// Map width
	int		map_height;	// Map height

	char		*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_player	*player;
	char		**map;

	t_ray		*ray;

}	t_cub;

t_cub	*init_cub(void);
void	prepare_the_game(t_cub *cub);
char	**get_map(void);
t_player	*init_player(t_cub *cub);
t_ray	*init_ray(void);
void	start_the_game(t_cub *cub);
int	ft_exit(t_cub *cub);


int	ft_game_loop(t_cub *cub);
void	clear_image(t_cub *cube);
void	cast_rays(t_cub *cub);
double	vertical_intersection(t_cub *cub, float angle);
double cast_single_ray(t_cub *cub, double vx, double vy, double x_step, double y_step);
double	horizontal_intersection(t_cub *cub, float angle);
int	wall_hit(float x, float y, t_cub *cub);
int	check_intersection(float angle, float *intersection, float *step, int is_horizon);
int	unit_circle(float angle, char c);


void	put_pixel(t_cub *cub, int x, int y, int color);
float	normal_angle(float angle);
void	render_wall(t_cub *cub, int ray);
void	draw_wall(t_cub *cub, int ray, double top_pixel, double bottom_pixel);
int	get_color(t_cub *cub, int wall_hit);
void	draw_floor_and_ceiling(t_cub *cub, int ray, double bottom_pixel, double top_pixel);


int	ft_key_press(int keycode, t_cub *cub);
int	ft_key_release(int keycode, t_cub *cub);
void	rotate_player(t_cub *cub, int i);
void	move_player(t_cub *cub, double move_x, double move_y);
void	hook_player(t_cub *cub);


#endif