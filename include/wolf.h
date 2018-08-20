/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:49:40 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/20 13:25:37 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <../libft/libft.h>
# include "SDL.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	
	int				w;
	int				h;
}	t_window;

typedef struct
{
	int	**map;
	
	int	sx;
	int	sy;
}	t_map;

typedef struct
{
	float	x;
	float	y;

	int		ix;
	int		iy;

	float	vx;
	float	vy;
	
	float	dirx;
	float	diry;

	float	sx;
	float	sy;

	float	rs;
	float	ms;
}	t_player;

typedef struct
{
	float	dirx;
	float	diry;

	float	ix;
	float	iy;

	float	dx;
	float	dy;

	float	sx;
	float	sy;

	float	p;
}	t_ray;

typedef	struct
{
	t_window	*win;
	t_map		*map;
	t_player	*plr;
	t_ray		*ray;
}	t_game;

int		get_map_dimensions(t_game *game, char *file);
void	get_map_data(t_game *game, char *file);

t_game	*init_game(void);
int		handle_input(t_game *game);

void	updateState(t_game *game);
void	renderState(t_game *game);

float	map(float value, float istart, float istop, float ostart, float ostop);

#endif