/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:09:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/20 17:42:47 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	handle_input(t_game *game)
{
	SDL_Event	e;
	float		oldDirX;
	float		oldScreenX;

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
				game->plr->vx = game->plr->dirx * game->plr->ms;
				game->plr->vy = game->plr->diry * game->plr->ms;
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				game->plr->vx = -game->plr->dirx * game->plr->ms;
				game->plr->vy = -game->plr->diry * game->plr->ms;
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
			// if (e.key.keysym.sym == SDLK_MINUS)
			// {
			// 	game->plr->sx += 0.1
			// }
			// printf("%f %f | %f %f\n", game->plr->dirx, game->plr->diry, game->plr->sx, game->plr->sy);
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
			if (e.key.keysym.sym == SDLK_LEFT)
			{
				// game->plr->vdirx = 0;
				// game->plr->vdiry = 0;
			}
			if (e.key.keysym.sym == SDLK_RIGHT)
			{
				// game->plr->vdirx = 0;
				// game->plr->vdiry = 0;
			}
		}
	}
	return (0);
}