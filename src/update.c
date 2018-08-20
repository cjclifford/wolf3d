/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:57:02 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/20 16:09:23 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	updateState(t_game *game)
{
	int	i;

	game->plr->x += game->plr->vx;
	game->plr->y += game->plr->vy;
	SDL_SetRenderDrawColor(game->win->ren, 113, 113, 113, 255);
	SDL_RenderClear(game->win->ren);
	SDL_SetRenderDrawColor(game->win->ren, 56, 56, 56, 255);
	i = 0;
	while (i < game->win->h / 2)
	{
		SDL_RenderDrawLine(game->win->ren, 0, i, game->win->w, i);
		i++;
	}
}