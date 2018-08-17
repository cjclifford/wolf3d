/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:26:20 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/14 16:27:54 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	map(float value, float istart, float istop, float ostart, float ostop)
{
	return (ostart + (ostop - ostart) * ((value - istart) / (istop - istart)));
}