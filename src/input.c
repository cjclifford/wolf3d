/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:09:04 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/23 13:48:54 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	check_keydown(t_game *game, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_UP)
		game->input->key_up = 1;
	if (e.key.keysym.sym == SDLK_DOWN)
		game->input->key_down = 1;
	if (e.key.keysym.sym == SDLK_LEFT)
		game->input->key_left = 1;
	if (e.key.keysym.sym == SDLK_RIGHT)
		game->input->key_right = 1;
	if (e.key.keysym.sym == SDLK_LSHIFT)
		game->input->key_lshift = 1;
}

static void	check_keyup(t_game *game, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_UP)
		game->input->key_up = 0;
	if (e.key.keysym.sym == SDLK_DOWN)
		game->input->key_down = 0;
	if (e.key.keysym.sym == SDLK_LEFT)
		game->input->key_left = 0;
	if (e.key.keysym.sym == SDLK_RIGHT)
		game->input->key_right = 0;
	if (e.key.keysym.sym == SDLK_LSHIFT)
		game->input->key_lshift = 0;
}

int			handle_input(t_game *game)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			return (1);
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			check_keydown(game, e);
		}
		else if (e.type == SDL_KEYUP)
			check_keyup(game, e);
	}
	return (0);
}
