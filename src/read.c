/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:56:23 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 10:52:41 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_map_dimensions(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**list;

	fd = open(file, O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		list = ft_strsplit(line, ' ');
		free(line);
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
		if (game->map->sy++ == 0)
			game->map->sx = i;
		if (i < game->map->sx)
			return (ret_err(WRONG_LINE));
	}
	if (i < 0)
		return (ret_err(MAP_ERROR));
	free(line);
	close(fd);
	return ((ret_err((game->map->sx == 0) * 2)));
}

static void	create_map(t_game *game)
{
	int	i;

	i = 0;
	game->map->map = (int **)malloc(sizeof(int *) * game->map->sy);
	while (i < game->map->sy)
		game->map->map[i++] = (int *)malloc(sizeof(int) * game->map->sx);
}

static void	get_map_value(t_game *game, char **list, int x, int y)
{
	if (ft_isdigit(*list[x]))
		game->map->map[y][x] = ft_atoi(list[x]);
	if (ft_strchr(list[x], 'S'))
	{
		game->plr->x = x;
		game->plr->y = y;
		game->map->map[y][x] = 0;
	}
}

void		get_map_data(t_game *game, char *file)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	**list;

	create_map(game);
	fd = open(file, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		free(line);
		x = 0;
		while (list[x])
		{
			get_map_value(game, list, x, y);
			free(list[x++]);
		}
		free(list);
		y++;
	}
	free(line);
	close(fd);
}
