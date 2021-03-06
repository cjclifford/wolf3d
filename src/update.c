/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:57:02 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/27 10:10:42 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	move_forward(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->plr->x + game->plr->dirx * game->plr->ms;
	new_y = game->plr->y + game->plr->diry * game->plr->ms;
	if (game->map->map[(int)(new_y)][(int)game->plr->x] == 0
			&& new_y < game->map->sy - 1 && new_y - 1 > 0)
		game->plr->y += game->plr->diry * game->plr->ms;
	if (game->map->map[(int)game->plr->y][(int)(new_x)] == 0
			&& new_x < game->map->sx - 1 && new_x - 1 > 0)
		game->plr->x += game->plr->dirx * game->plr->ms;
}

static void	move_back(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->plr->x - game->plr->dirx * game->plr->ms;
	new_y = game->plr->y - game->plr->diry * game->plr->ms;
	if (game->map->map[(int)(new_y)][(int)game->plr->x] == 0
			&& new_y < game->map->sy - 1 && new_y - 1 > 0)
		game->plr->y -= game->plr->diry * game->plr->ms;
	if (game->map->map[(int)game->plr->y][(int)(new_x)] == 0
			&& new_x < game->map->sx - 1 && new_x - 1 > 0)
		game->plr->x -= game->plr->dirx * game->plr->ms;
}

static void	look_left(t_game *game)
{
	float	old_dir_x;
	float	old_screen_x;

	old_dir_x = game->plr->dirx;
	old_screen_x = game->plr->sx;
	game->plr->dirx = game->plr->dirx * cos(-game->plr->rs) -
		game->plr->diry * sin(-game->plr->rs);
	game->plr->diry = old_dir_x * sin(-game->plr->rs) +
		game->plr->diry * cos(-game->plr->rs);
	game->plr->sx = game->plr->sx * cos(-game->plr->rs) -
		game->plr->sy * sin(-game->plr->rs);
	game->plr->sy = old_screen_x * sin(-game->plr->rs) +
		game->plr->sy * cos(-game->plr->rs);
}

static void	look_right(t_game *game)
{
	float	old_dir_x;
	float	old_screen_x;

	old_dir_x = game->plr->dirx;
	old_screen_x = game->plr->sx;
	game->plr->dirx = game->plr->dirx * cos(game->plr->rs) -
		game->plr->diry * sin(game->plr->rs);
	game->plr->diry = old_dir_x * sin(game->plr->rs) +
		game->plr->diry * cos(game->plr->rs);
	game->plr->sx = game->plr->sx * cos(game->plr->rs) -
		game->plr->sy * sin(game->plr->rs);
	game->plr->sy = old_screen_x * sin(game->plr->rs) +
		game->plr->sy * cos(game->plr->rs);
}

void		update_state(t_game *game)
{
	int		i;

	if (game->input->key_lshift)
	{
		game->plr->ms *= 2;
		game->plr->rs *= 2;
	}
	if (game->input->key_up)
		move_forward(game);
	if (game->input->key_down)
		move_back(game);
	if (game->input->key_left)
		look_left(game);
	if (game->input->key_right)
		look_right(game);
	SDL_SetRenderDrawColor(game->win->ren, 46, 169, 22, 255);
	SDL_RenderClear(game->win->ren);
	SDL_SetRenderDrawColor(game->win->ren, 27, 111, 217, 255);
	i = 0;
	while (i < game->win->h / 2)
	{
		SDL_RenderDrawLine(game->win->ren, 0, i, game->win->w, i);
		i++;
	}
}
