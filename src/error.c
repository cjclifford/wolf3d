/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:34:29 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 10:55:32 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ret_err(int error)
{
	if (error == WRONG_LINE)
		ft_putendl("Found wrong line length. Exiting.");
	else if (error == NO_DATA)
		ft_putendl("No data found in file. Exiting.");
	else if (error == MAP_ERROR)
		ft_putendl("Error loading map. Exiting");
	else if (error == NO_FILE)
		ft_putendl("Map file not found. Exiting");
	else
		return (1);
	return (0);
}
