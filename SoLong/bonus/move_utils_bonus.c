/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:15:30 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 17:28:05 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_move_bonus(t_conf *conf, int x, int y)
{
	if (conf->map[x][y] != 'E' && conf->map[x][y] != '1')
	{
		conf->count++;
		printf("count : %d\n", conf->count);
	}
}

int	map_size_bonus(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_pos_z	zero_pos_bonus(char **map)
{
	t_pos_z	pos_z;

	pos_z.x = 0;
	while (map[pos_z.x])
	{
		pos_z.y = 0;
		while (map[pos_z.x][pos_z.y])
		{
			if (map[pos_z.x][pos_z.y] == '0')
				return (pos_z);
			pos_z.y++;
		}
		pos_z.x++;
	}
	return (pos_z);
}
