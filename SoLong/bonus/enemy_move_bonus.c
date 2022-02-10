/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:42:52 by imabid            #+#    #+#             */
/*   Updated: 2022/02/09 20:49:49 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_enemy(char **map)
{
	t_pos_z	pos_z;

	pos_z = zero_pos_bonus(map);
	if (map[pos_z.x][pos_z.y] == '0')
		map[pos_z.x][pos_z.y] = 'Y';
}

void	exit_enemy(t_conf *conf, t_pos_en pos_en)
{
	if (conf->map[pos_en.x][pos_en.y - 1] == 'P'
		|| conf->map[pos_en.x][pos_en.y + 1] == 'P'
		|| conf->map[pos_en.x + 1][pos_en.y] == 'P'
		|| conf->map[pos_en.x - 1][pos_en.y] == 'P')
		exit(0);
}

void	move_enemy(t_conf *conf, t_pos_en pos_en)
{
	static int	a;

	a = rand();
	exit_enemy(conf, pos_en);
	if (conf->map[pos_en.x][pos_en.y + 1] == '0' && a % 2)
	{
		conf->map[pos_en.x][pos_en.y] = '0';
		conf->map[pos_en.x][pos_en.y + 1] = 'Y';
	}
	else if (conf->map[pos_en.x + 1][pos_en.y] == '0' && !(a % 2))
	{
		conf->map[pos_en.x][pos_en.y] = '0';
		conf->map[pos_en.x + 1][pos_en.y] = 'Y';
	}
	else if (conf->map[pos_en.x - 1][pos_en.y] == '0' && (a % 2))
	{
		conf->map[pos_en.x][pos_en.y] = '0';
		conf->map[pos_en.x - 1][pos_en.y] = 'Y';
	}
	else if (conf->map[pos_en.x][pos_en.y - 1] == '0' && !(a % 2))
	{
		conf->map[pos_en.x][pos_en.y] = '0';
		conf->map[pos_en.x][pos_en.y - 1] = 'Y';
	}
}

int	enemy_move_bonus(void *param)
{
	t_all	all;

	all.conf = (t_conf *)param;
	all.pos_en = enemy_pos_bonus(all.conf->map);
	if (all.staticc.i++ < 50)
	{
		move_enemy(all.conf, all.pos_en);
		if (all.staticc.i >= 50)
			all.staticc.f = 0;
		aff_imag_bonus(all.conf);
	}
	else
	{
		if (all.staticc.f++ < 50)
		{
			move_enemy(all.conf, all.pos_en);
			if (all.staticc.f >= 50)
				all.staticc.i = 0;
			aff_imag_bonus(all.conf);
		}
	}
	aff_imag_bonus(all.conf);
	usleep(50000);
	return (0);
}
