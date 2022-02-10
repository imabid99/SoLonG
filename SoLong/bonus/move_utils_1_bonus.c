/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:15:47 by imabid            #+#    #+#             */
/*   Updated: 2022/01/21 16:18:27 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos_en	enemy_pos_bonus(char **map)
{
	t_pos_en	pos_en;

	pos_en.x = 0;
	while (map[pos_en.x])
	{
		pos_en.y = 0;
		while (map[pos_en.x][pos_en.y])
		{
			if (map[pos_en.x][pos_en.y] == 'Y')
				return (pos_en);
			pos_en.y++;
		}
		pos_en.x++;
	}
	return (pos_en);
}

t_pos	player_pos_bonus(char **map)
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

int	check_coin_bonus(char **map)
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
