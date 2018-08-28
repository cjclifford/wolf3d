/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:05:43 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 10:43:55 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->win = (t_window *)malloc(sizeof(t_window));
	game->win->w = 800;
	game->win->h = 600;
	game->win->win = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, game->win->w, game->win->h, SDL_WINDOW_SHOWN);
	game->win->ren = SDL_CreateRenderer(game->win->win, -1, 0);
	game->plr = (t_player *)malloc(sizeof(t_player));
	game->plr->dirx = 1;
	game->plr->diry = 1;
	game->plr->sx = -0.66;
	game->plr->sy = 0.66;
	game->map = (t_map *)malloc(sizeof(t_map));
	game->map->sx = 0;
	game->map->sy = 0;
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	game->input = (t_input *)malloc(sizeof(t_input));
	game->input->key_up = 0;
	game->input->key_down = 0;
	game->input->key_left = 0;
	game->input->key_right = 0;
	game->input->key_lshift = 0;
	return (game);
}
