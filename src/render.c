/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:58:44 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/17 18:03:54 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	drawMapPosition(t_game *game, float x1, float y1)
{
	int x2 = game->plr->dirx * 6 + x1;
	int y2 = game->plr->diry * 6 + y1;
	SDL_SetRenderDrawColor(game->win->ren, 255, 255, 255, 255);
	SDL_RenderDrawLine(game->win->ren, x1, y1, x2, y2);
}

static void	draw_map(t_game *game)
{
	int	i;
	int	j;
	int	scale;

	i = 0;
	j = 0;
	scale = 6;
	SDL_SetRenderDrawColor(game->win->ren, 0, 0, 0, 255);
	SDL_Rect rect;
	i = 0;
	while (i < game->map->sy)
	{
		j = 0;
		while (j < game->map->sx)
		{
			rect.x = j * scale;
			rect.y = i * scale;
			rect.w = scale;
			rect.h = scale;
			if (game->map->map[i][j] > 0)
			{
				if (game->map->map[i][j] == 1)
					SDL_SetRenderDrawColor(game->win->ren, 0, 0, 255, 255);
				else if (game->map->map[i][j] == 2)
					SDL_SetRenderDrawColor(game->win->ren, 255, 0, 0, 255);
				else if (game->map->map[i][j] == 3)
					SDL_SetRenderDrawColor(game->win->ren, 0, 255, 0, 255);
				else if (game->map->map[i][j] == 4)
					SDL_SetRenderDrawColor(game->win->ren, 255, 0, 255, 255);
				else
					SDL_SetRenderDrawColor(game->win->ren, 255, 255, 0, 255);
				SDL_RenderDrawRect(game->win->ren, &rect);
			}
			j++;
		}
		i++;
	}
	SDL_SetRenderDrawColor(game->win->ren, 255, 255, 255, 255);
	drawMapPosition(game, game->plr->x * scale, game->plr->y * scale);
}

void		renderState(t_game *game)
{
	int		x;
	int		hit;
	int		side;
	int		wallHeight;
	int		wallStart;
	int		wallEnd;
	SDL_Colour	colour;

	//raycasting loop
	x = 0;
	while (x < game->win->w)
	{
		// get map pos
		game->plr->ix = (int)game->plr->x;
		game->plr->iy = (int)game->plr->y;
		// get ray direction
		game->ray->dirx = game->plr->dirx + game->plr->sx * (2 * x / (float)game->win->w - 1);
		game->ray->diry = game->plr->diry + game->plr->sy * (2 * x / (float)game->win->w - 1);
		// get delta distance
		game->ray->dx = fabs(1.0 / game->ray->dirx);
		game->ray->dy = fabs(1.0 / game->ray->diry);
		// set intersect and step amount
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
		// DDA
		hit = 0;
		while (!hit)
		{
			// if (game->ray->ix > game->map->sx || game->ray->ix < 0)
			// 	break ;
			// if (game->ray->iy > game->map->sy || game->ray->iy < 0)
			// 	break ;
			if (game->ray->ix < game->ray->iy)
			{
				game->ray->ix += game->ray->dx;
				game->plr->ix += game->ray->sx;
				side = 0;
			}
			else
			{
				game->ray->iy += game->ray->dy;
				game->plr->iy += game->ray->sy;
				side = 1;
			}
			if (game->map->map[(int)game->plr->iy][(int)game->plr->ix] > 0)
				hit = 1;
		}
		// calculate distance from wall
		if (side == 0)
			game->ray->p = (game->plr->ix - game->plr->x + (1 - game->ray->sx) / 2) / game->ray->dirx;
		else
			game->ray->p = (game->plr->iy - game->plr->y + (1 - game->ray->sy) / 2) / game->ray->diry;
		// calculate height of wall
		wallHeight = (int)(game->win->h / game->ray->p);
		// calculate lowest and heighest pixel of wall
		wallStart = -wallHeight / 2 + game->win->h / 2;
		if (wallStart < 0)
			wallStart = 0;
		wallEnd = wallHeight / 2 + game->win->h / 2;
		if (wallEnd > game->win->h)
			wallEnd = game->win->h - 1;
		// choose wall colour
		colour.a = 255;
		if (game->map->map[game->plr->iy][game->plr->ix] == 1)
		{
			colour.r = 0;
			colour.g = 0;
			colour.b = 255;
		}
		else if (game->map->map[game->plr->iy][game->plr->ix] == 2)
		{
			colour.r = 255;
			colour.g = 0;
			colour.b = 0;
		}
		else if (game->map->map[game->plr->iy][game->plr->ix] == 3)
		{
			colour.r = 0;
			colour.g = 255;
			colour.b = 0;
		}
		else if (game->map->map[game->plr->iy][game->plr->ix] == 4)
		{
			colour.r = 255;
			colour.g = 0;
			colour.b = 255;
		}
		else
		{
			colour.r = 255;
			colour.g = 255;
			colour.b = 0;
		}
		// change brightness of wall respectively
		if (side == 1)
		{
			colour.r /= 2;
			colour.g /= 2;
			colour.b /= 2;
		}
		SDL_SetRenderDrawColor(game->win->ren, colour.r, colour.g, colour.b, colour.a);
		//draw pixels as vertical line
		SDL_RenderDrawLine(game->win->ren, x, wallStart, x, wallEnd);
		x++;
	}
	draw_map(game);
	SDL_RenderPresent(game->win->ren);
}