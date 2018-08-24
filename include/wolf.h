/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:49:40 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/23 13:55:12 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <../libft/libft.h>
# include "SDL.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_window
{
	SDL_Window		*win;
	SDL_Renderer	*ren;

	int				w;
	int				h;
}				t_window;

typedef struct	s_map
{
	int	**map;

	int	sx;
	int	sy;
}				t_map;

typedef struct	s_player
{
	float	x;
	float	y;

	int		ix;
	int		iy;

	float	dirx;
	float	diry;

	float	sx;
	float	sy;

	float	rs;
	float	ms;
}				t_player;

typedef struct	s_ray
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
}				t_ray;

typedef	struct	s_input
{
	int	key_up;
	int	key_down;
	int	key_left;
	int	key_right;
	int	key_lshift;
}				t_input;

typedef	struct	s_game
{
	int			curr_time;
	int			old_time;
	float		frame_time;

	t_window	*win;
	t_map		*map;
	t_player	*plr;
	t_ray		*ray;
	t_input		*input;
}				t_game;

int				get_map(t_game *game, char *file);

t_game			*init_game(void);
int				handle_input(t_game *game);

void			update_state(t_game *game);
void			render_state(t_game *game);

void			get_map_data(t_game *game, char *file);
int				get_map_dimensions(t_game *game, char *file);

#endif
