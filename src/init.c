/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:05:43 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/17 16:19:57 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));

	game->win = (t_window *)malloc(sizeof(t_window));
	game->win->w = 640;
	game->win->h = 430;
	game->win->win = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->win->w, game->win->h, SDL_WINDOW_SHOWN);
	game->win->ren = SDL_CreateRenderer(game->win->win, -1, SDL_RENDERER_ACCELERATED);

	game->plr = (t_player *)malloc(sizeof(t_player));
	game->plr->x = 10;
	game->plr->y = 10;
	game->plr->vx = 0;
	game->plr->vy = 0;
	game->plr->dirx = 1;
	game->plr->diry = 1;
	game->plr->sx = 0;
	game->plr->sy = 0.66;

	game->map = (t_map *)malloc(sizeof(t_map));

	game->ray = (t_ray *)malloc(sizeof(t_ray));
	return (game);
}