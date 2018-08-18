/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:09:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/17 16:11:14 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	handle_input(t_game *game)
{
	SDL_Event	e;
	int			oldDirX;
	int			oldScreenX;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			return (1);
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			if (e.key.keysym.sym == SDLK_UP)
			{
				if (game->map->map[(int)game->plr->y][(int)(game->plr->x + game->plr->dirx * game->plr->ms)] == 0)
					game->plr->x += game->plr->dirx * game->plr->ms;
				if (game->map->map[(int)(game->plr->y + game->plr->diry * game->plr->ms)][(int)game->plr->x] == 0)
					game->plr->y += game->plr->diry * game->plr->ms;
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				if (game->map->map[(int)game->plr->y][(int)(game->plr->x - game->plr->dirx * game->plr->ms)] == 0)
					game->plr->x -= game->plr->dirx * game->plr->ms;
				if (game->map->map[(int)(game->plr->y - game->plr->diry * game->plr->ms)][(int)game->plr->x] == 0)
					game->plr->y -= game->plr->diry * game->plr->ms;
			}
			if (e.key.keysym.sym == SDLK_LEFT)
			{
				oldDirX = game->plr->dirx;
				game->plr->dirx = game->plr->dirx * cos(-game->plr->rs) - game->plr->diry * sin(-game->plr->rs);
				game->plr->diry = oldDirX * sin(-game->plr->rs) + game->plr->diry * cos(-game->plr->rs);
				oldScreenX = game->plr->sx;
				game->plr->sx = game->plr->sx * cos(-game->plr->rs) - game->plr->sy * sin(-game->plr->rs);
				game->plr->sy = oldScreenX * sin(-game->plr->rs) + game->plr->sy * cos(-game->plr->rs);
			}
			if (e.key.keysym.sym == SDLK_RIGHT)
			{
				oldDirX = game->plr->dirx;
				game->plr->dirx = game->plr->dirx * cos(game->plr->rs) - game->plr->diry * sin(game->plr->rs);
				game->plr->diry = oldDirX * sin(game->plr->rs) + game->plr->diry * cos(game->plr->rs);
				oldScreenX = game->plr->sx;
				game->plr->sx = game->plr->sx * cos(game->plr->rs) - game->plr->sy * sin(game->plr->rs);
				game->plr->sy = oldScreenX * sin(game->plr->rs) + game->plr->sy * cos(game->plr->rs);
			}
		}
		else if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_UP)
			{
				game->plr->vx = 0;
				game->plr->vy = 0;
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				game->plr->vx = 0;
				game->plr->vy = 0;
			}
			// if (e.key.keysym.sym == SDLK_LEFT)
			// if (e.key.keysym.sym == SDLK_RIGHT)
		}
	}
	return (0);
}