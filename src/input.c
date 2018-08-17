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
	SDL_Event e;

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
				printf("%f\n", game->plr->dir);
				game->plr->vx = cos(game->plr->dir) * 0.05f;
				game->plr->vy = sin(game->plr->dir) * 0.05f;
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				game->plr->vy = -sin(game->plr->dir) * 0.05f;
				game->plr->vx = -cos(game->plr->dir) * 0.05f;
			}
			if (e.key.keysym.sym == SDLK_LEFT)
				game->plr->vdir = -(2 * M_PI) / 500;
			if (e.key.keysym.sym == SDLK_RIGHT)
				game->plr->vdir = (2 * M_PI) / 500;
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
				game->plr->vdir = 0;
			if (e.key.keysym.sym == SDLK_RIGHT)
				game->plr->vdir = 0;
		}
	}
	return (0);
}