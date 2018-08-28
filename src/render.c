/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:58:44 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/27 11:55:44 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	get_step(t_game *game)
{
	if (game->ray->dirx < 0)
	{
		game->ray->sx = -1;
		game->ray->ix = (game->plr->x - game->plr->ix) * game->ray->dx;
	}
	else
	{
		game->ray->sx = 1;
		game->ray->ix = (game->plr->ix + 1.0 - game->plr->x) * game->ray->dx;
	}
	if (game->ray->diry < 0)
	{
		game->ray->sy = -1;
		game->ray->iy = (game->plr->y - game->plr->iy) * game->ray->dy;
	}
	else
	{
		game->ray->sy = 1;
		game->ray->iy = (game->plr->iy + 1.0 - game->plr->y) * game->ray->dy;
	}
}

static void	dda(t_game *game, int *side)
{
	int	hit;

	hit = 0;
	*side = -1;
	while (!hit)
	{
		if (game->plr->ix + 1 >= game->map->sx || game->plr->ix - 1 < 0
			|| game->plr->iy + 1 >= game->map->sy || game->plr->iy - 1 < 0)
			break ;
		if (game->ray->ix < game->ray->iy)
		{
			game->ray->ix += game->ray->dx;
			game->plr->ix += game->ray->sx;
			*side = 0;
		}
		else
		{
			game->ray->iy += game->ray->dy;
			game->plr->iy += game->ray->sy;
			*side = 1;
		}
		if (game->map->map[(int)game->plr->iy][(int)game->plr->ix] > 0)
			hit = 1;
	}
}

static void	set_colour(t_game *game, int side)
{
	SDL_Colour colour;

	colour.r = 0;
	colour.g = 0;
	colour.b = 0;
	if (side == 0)
	{
		if (game->ray->sx == -1)
			colour.r = 255;
		else
			colour.g = 255;
	}
	else if (side == 1)
	{
		if (game->ray->sy == -1)
			colour.b = 255;
		else
		{
			colour.r = 255;
			colour.b = 255;
		}
	}
	SDL_SetRenderDrawColor(game->win->ren, colour.r, colour.g, colour.b, 255);
}

static void	draw_wall(t_game *game, int side, int x)
{
	int		wall_height;
	int		wall_start;
	int		wall_end;

	if (side >= 0)
	{
		if (side == 0)
			game->ray->p = (game->plr->ix - game->plr->x +
			(1 - game->ray->sx) / 2) / game->ray->dirx;
		else if (side == 1)
			game->ray->p = (game->plr->iy - game->plr->y +
			(1 - game->ray->sy) / 2) / game->ray->diry;
		wall_height = (int)(game->win->h / game->ray->p);
		wall_start = -wall_height / 2 + game->win->h / 2;
		if (wall_start < 0)
			wall_start = 0;
		wall_end = wall_height / 2 + game->win->h / 2;
		if (wall_end > game->win->h)
			wall_end = game->win->h - 1;
		SDL_RenderDrawLine(game->win->ren, x, wall_start, x, wall_end);
	}
}

void		render_state(t_game *game)
{
	int		x;
	int		side;

	x = 0;
	while (x < game->win->w)
	{
		game->plr->ix = (int)game->plr->x;
		game->plr->iy = (int)game->plr->y;
		game->ray->dirx = game->plr->dirx + game->plr->sx *
			(2 * x / (float)game->win->w - 1);
		game->ray->diry = game->plr->diry + game->plr->sy *
			(2 * x / (float)game->win->w - 1);
		game->ray->dx = fabs(1.0 / game->ray->dirx);
		game->ray->dy = fabs(1.0 / game->ray->diry);
		get_step(game);
		dda(game, &side);
		set_colour(game, side);
		draw_wall(game, side, x);
		x++;
	}
	SDL_RenderPresent(game->win->ren);
}
