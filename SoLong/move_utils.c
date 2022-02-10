/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:15:30 by imabid            #+#    #+#             */
/*   Updated: 2022/01/18 16:43:39 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_conf *conf, int x, int y)
{
	static int	a;

	if (conf->map[x][y] != 'E' && conf->map[x][y] != '1')
	{
		a++;
		printf("count : %d\n", a);
	}
}

int	map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_pos	player_pos(char **map)
{
	t_pos	pos;

	pos.x = 0;
	while (map[pos.x])
	{
		pos.y = 0;
		while (map[pos.x][pos.y])
		{
			if (map[pos.x][pos.y] == 'P')
				return (pos);
			pos.y++;
		}
		pos.x++;
	}
	return (pos);
}

int	check_coin(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
