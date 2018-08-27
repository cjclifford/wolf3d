/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:29:12 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/27 09:53:17 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "SDL.h"

static void	frame_calc(t_game *game)
{
	game->old_time = game->curr_time;
	game->curr_time = SDL_GetTicks();
	game->frame_time = (game->curr_time - game->old_time) / 1000.0;
	game->plr->rs = 2 * game->frame_time;
	game->plr->ms = 3 * game->frame_time;
}

static int	load_error(void)
{
	ft_putendl("Map not found.");
	return (0);
}

int			main(int ac, char **av)
{
	t_game	*game;
	int		quit;

	if (ac != 2)
		return (0);
	SDL_Init(SDL_INIT_VIDEO);
	game = init_game();
	if (open(av[1], O_RDONLY) < 0)
		return (load_error());
	if (!get_map_dimensions(game, av[1]))
		return (0);
	game->plr->x = game->map->sx / 2;
	game->plr->y = game->map->sy / 2;
	get_map_data(game, av[1]);
	game->curr_time = SDL_GetTicks();
	quit = 0;
	while (!quit)
	{
		frame_calc(game);
		quit = handle_input(game);
		update_state(game);
		render_state(game);
	}
	return (0);
}
