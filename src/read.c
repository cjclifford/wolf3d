/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:56:23 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/17 09:07:17 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		get_map_dimensions(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**list;

	fd = open(file, O_RDONLY);
	game->map->sy = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		free(line);
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
		if (game->map->sy == 0)
			game->map->sx = i;
		if (i < game->map->sx)
			return (0);//return (wrong_line());
		game->map->sy++;
	}
	if (game->map->sx == 0)
		return (0);//return (no_data());
	close(fd);
	return (1);
}

void	get_map_data(t_game *game, char *file)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	**list;

	game->map->map = (int **)malloc(sizeof(int *) * game->map->sy);
	y = 0;
	while (y < game->map->sy)
	{
		game->map->map[y] = (int *)malloc(sizeof(int) * game->map->sx);
		y++;
	}
	fd = open(file, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		free(line);
		x = 0;
		while (list[x])
		{
			if (ft_isdigit(*list[x]))
				game->map->map[y][x] = ft_atoi(list[x]);
			// get player position
			if (ft_strchr(list[x], 'S'))
			{
				game->plr->x = x;
				game->plr->y = y;
			}
			free(list[x]);
			x++;
		}
		free(list);
		y++;
	}
	close(fd);
}