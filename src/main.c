/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:29:12 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/20 17:58:13 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "SDL.h"

int	main(int ac, char **av)
{
	t_game *game;
	int quit;

	if (ac != 2)
		return (0);
	SDL_Init(SDL_INIT_VIDEO);
	game = init_game();
	get_map_dimensions(game, av[1]);
	get_map_data(game, av[1]);
	quit = 0;
	while(!quit)
	{
		quit = handle_input(game);
		updateState(game);
		renderState(game);
		game->plr->rs = 5 * (M_PI / 180.0);
		game->plr->ms = 0.01;
	}
	return (0);
}