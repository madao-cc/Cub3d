/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:58:36 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/15 20:18:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "cub_bonus.h"

// Forward declaration of t_cub
typedef struct s_cub	t_cub;

# define RAY_COLOR	0x00FF00
# define PLAYER_COLOR	0xFF0000
# define WALL_COLOR	0x0000FF
# define VOID_COLOR	0x000000
# define MINIMAP_SCALE	0.5
# define MINIMAP_RAY_COUNT	60

typedef struct s_point
{
	int		x;
	int		y;
}		t_point;

typedef struct s_minimap
{
	double	ray_angle;
	double	h_inter;
	double	v_inter;
	double	distance;
	double	hit_x;
	double	hit_y;
	double	step;
}	t_minimap;

void		draw_minimap(t_cub *cub);
t_point		calculate_delta(t_point *start, t_point *end);
t_point		calculate_step(t_point *start, t_point *end);
void		draw_line(t_cub *cub, t_point *start, t_point *end, int color);
void		draw_tile(t_cub *cub, int row, int collum, int tile_size);
void		draw_minimap_player(t_cub *cub);
void		draw_minimap_rays(t_cub *cub);
void		get_minimap_ray(t_cub *cub, int i, t_minimap *minimap);
void		check_error(int *error, t_point delta, \
	t_point step, t_point *current);

#endif